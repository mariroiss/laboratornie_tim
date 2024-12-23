#include <iostream>
#include "GN.h"
#include "gn_utils.h"
#include "dfs_by_Makkoveeva.h"
#include "Deikstra.h"
#include "EdmondsKarp_1.h"

using namespace std;


void GasNetwork::addPipe() {
    Pipe p;
    p.AddPipe();
    this->pipesmap.emplace(p.GetId(), p);
}


void GasNetwork::addCS() {
    CS cs;
    cs.AddCS();
    this->cssmap.emplace(cs.GetId(), cs);
}


void GasNetwork::delete_selectedPipes() {
    int counter = 0;
    for (auto it = this->selected_pipes.begin(); it != this->selected_pipes.end();) {
        if (!this->pipesmap.at(*it).IsUsing()) {
            this->erase_obj(this->pipesmap, *it);
            it = this->selected_pipes.erase(it);
            ++counter;
        }
        else {
            std::cout << "Pipe " << *it << " used in graph" << std::endl;
            ++it;
        }
    }
    cout << counter << "pipes was erased!" << endl;
}


void GasNetwork::delete_selectedCS() {
    int counter = 0;
    for (auto it = this->selected_cs.begin(); it != this->selected_cs.end();) {
        if (!this->cssmap.at(*it).IsUsing()) {
            this->erase_obj(this->cssmap, *it);
            it = this->selected_cs.erase(it);
            ++counter;
        }
        else {
            cout << "CS " << *it << " used in graph" << endl;
            ++it;
        }
    }
    cout << counter << "cs was erased!" << endl;
}


void GasNetwork::createGraph() {
    this->graph.clear();

    for (const auto& [id, cs] : this->cssmap) {
        auto pipes = cs.get_links();
        if (pipes[1].size()) {
            for (const auto& pipe_id : pipes[1])
                this->graph[id].emplace(this->pipesmap.at(pipe_id).get_links()[1]);
                
        }

        else if (cs.IsUsing()) {
            this->graph[id] = {};
        }
    }
}


void GasNetwork::showGraph(){
    //this->createGraph();

    cout << "graph:" << endl;
    for (const auto& pair : this->graph) {
        cout << pair.first << " --> ";
        for (const auto& v : pair.second)
            cout << " " << v;
        cout << endl;
    }
}


bool GasNetwork::connect() {
    if (this->cssmap.size() < 2)
        return false;

    
    cout << "output id: ";
    int output_id;

    while (1) {
        output_id = GetCorrectNumber(1, 10000);
        if (this->cssmap.contains(output_id))
            break;
        else
            cout << "input correct id: " << endl;
    }

    cout << "input id: ";
    int input_id;

    while (1) {
        input_id = GetCorrectNumber(1, 10000);
        if (this->cssmap.contains(input_id))
            break;
        else
            cout << "input correct id: " << endl;
    }

    cout << "pipe's diameter: ";
    int diameter = GetCorrectDiameter();
    int pipe_id = this->FindByDiameter(diameter);

    this->cssmap.at(output_id).addLink(1, pipe_id);
    this->pipesmap.at(pipe_id).set_links(output_id, input_id);
    this->cssmap.at(input_id).addLink(0, pipe_id);

    return true;
}



bool GasNetwork::make_TS() {
    this->TSorder = dfs_by_Makkoveeva(this->graph);

    cout << "TS: ";
    if (this->TSorder.size()) {
        for (const auto& v : this->TSorder)
            cout << v << " ";
    }
    else {
        cout << "graph has cycle or TS is empty set!" << endl;
    }

    cout << endl;

    return 1;
}


void GasNetwork::delete_GraphPipe(Pipe& pipe) {
    auto links = pipe.get_links();

    CS& cs_0 = this->cssmap.at(links[0]);
    CS& cs_1 = this->cssmap.at(links[1]);

    cs_0.deleteLink(1, pipe.GetId());
    cs_1.deleteLink(0, pipe.GetId());
    pipe.set_links(0, 0);
}


void GasNetwork::delete_GraphCS(CS& cs) {
    for (auto& neig : cs.get_links()) {
        for (auto& pipe : neig) {
            this->delete_GraphPipe(this->pipesmap.at(pipe));
        }
    }
}


void GasNetwork::clearGraph() {
    for (auto& [id, _] : this->graph) {
        this->delete_GraphCS(this->cssmap.at(id));
    }
}


void GasNetwork::delPipe() {
    int id;
    int a;

    while (true) {
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber(0, 10000);

        if (id == 0)
            break;

        if (!this->pipesmap.contains(id))
            continue;

        if (this->pipesmap.at(id).IsUsing())
            cout << "do you really want to delete pipe (0-no, 1-yes): ";
            a = GetCorrectNumber(0, 1);
            if (a == 1)
                this->delete_GraphPipe(this->pipesmap.at(id));
            else
                break;
    }
}


void GasNetwork::delCS() {
    int id;
    int b;
    while (true) {
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber(0, 10000);

        if (id == 0)
            break;

        if (!this->cssmap.contains(id))
            continue;

        if (this->cssmap.at(id).IsUsing())
            cout << "do you really want to delete cs (0-no, 1-yes): ";
            b = GetCorrectNumber(0, 1);
            if (b == 1)
                this->delete_GraphCS(this->cssmap.at(id));
            else
                break;
    }
}



std::unordered_set<int> GasNetwork::get_IncidentPipes(const int& id_1, const int& id_2) {
    std::unordered_set<int> result = {};
    auto neighbours_pipes = this->cssmap.at(id_1).get_links();
    for (const auto& pipeID : neighbours_pipes[1]) {
        const Pipe& pipe = this->pipesmap.at(pipeID);
        if (pipe.get_links()[1] == id_2)
            result.emplace(pipeID);
    }

    return result;
}


int GasNetwork::getMINDistance(const int& id_1, const int& id_2) {
    const std::unordered_set<int> incidentPipes = this->get_IncidentPipes(id_1, id_2);

    if (!incidentPipes.size())
        return this->INF;

    int min_len = this->INF;

    for (const auto& pipeID : incidentPipes) {
        if (this->pipesmap.at(pipeID).GetRepair()) {
            const int& pipe_len = this->pipesmap.at(pipeID).get_length();
            if (pipe_len < min_len)
                min_len = pipe_len;
        }
    }

    return min_len;
}


void GasNetwork::displayMinimumPath() {
    cout << "Minimum path: ";
    if (this->min_path.empty()) {
        cout << "cant find min path!" << endl;
        return;
    }

    if (this->min_path.size() > 1) {
        int dist = 0;
        for (int i = 0; i < this->min_path.size() - 1; ++i) {
            dist += this->getMINDistance(this->min_path[i], this->min_path[i + 1]);
            cout << this->min_path[i] << " ";
        }
        cout << this->min_path[this->min_path.size() - 1] << endl;
        cout << "Total Distance = " << dist << endl;
    }
    else {
        cout << this->min_path[0] << endl;
        cout << "Total Distance = " << 0 << endl;
    }
    cout << endl;
}


void GasNetwork::calculateMinimumDistance() {
    if (this->graph.empty()) {
        cout << "The graph does not exist!" << endl;
        return;
    }

    cout << "start id: ";
    int start_id;

    while (1) {
        start_id = GetCorrectNumber(1, 10000);
        if (this->graph.contains(start_id))
            break;
        else
            cout << "input correct start id: " << endl;
    }

    cout << "end id: ";
    int end_id;

    while (1) {
        end_id = GetCorrectNumber(1, 10000);
        if (this->graph.contains(end_id))
            break;
        else
            cout << "input correct end id: " << endl;
    }

    this->min_path = this->metodDeikstra(start_id, end_id);

    this->displayMinimumPath();
}



int GasNetwork::getSUMproductivity(const int& id_1, const int& id_2) {
    const std::unordered_set<int> incidentPipes = this->get_IncidentPipes(id_1, id_2);
    int capacity = 0;

    for (const auto& pipeID : incidentPipes) {
        capacity += this->pipesmap.at(pipeID).get_productivity();
    }

    return capacity;
}


void GasNetwork::show_maxFlow() {
    cout << "Way with max flow: ";
    for (const auto& csID : this->maxFlow_path) {
        cout << csID << " ";
    }
    cout << endl;

    cout << "max flow = " << this->maxFlow << endl;
}


void GasNetwork::count_maxFlow() {
    if (!this->graph.size()) {
        cout << "The graph does not exist!" << endl;
        cout << "Max flow = 0" << endl;
        return;
    }

    
    cout << "source id: ";
    int source_id;

    while (1) {
        source_id = GetCorrectNumber(1, 10000);
        if (this->graph.contains(source_id))
            break;
        else
            cout << "input correct source id: " << endl;
    }

    cout << "sink id: ";
    int sink_id;

    while (1) {
        sink_id = GetCorrectNumber(1, 10000);
        if (this->graph.contains(sink_id))
            break;
        else
            cout << "input correct sink id: " << endl;
    }

    std::vector<int> flowPath = this->metodDeikstra(source_id, sink_id);
    if (!flowPath.size()) {
        cout << "No way: max flow = 0" << endl;
    }
    else if (flowPath.size() == 1) {
        cout << "max flow = INF" << endl;
        cout << "max flow path: " << flowPath[0] << endl;
    }
    else {
        this->maxFlow = this->edmondsKarp<int>(source_id, sink_id);
        this->show_maxFlow();
    }
}
