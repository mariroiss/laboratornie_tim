#include <iostream>
#include "GN.h"
#include "gn_utils.h"
#include "dfs_by_Makkoveeva.h"

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
            std::cout << "CS " << *it << " used in graph" << std::endl;
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


void GasNetwork::showGraph() const{
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
    this->cssmap.at(pipe.get_links()[0]).deleteLink(1, pipe.GetId());
    this->cssmap.at(pipe.get_links()[1]).deleteLink(0, pipe.GetId());
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

    while (true) {
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber(0, 10000);

        if (id == 0)
            break;

        if (!this->pipesmap.contains(id))
            continue;

        if (this->pipesmap.at(id).IsUsing())
            this->delete_GraphPipe(this->pipesmap.at(id));
    }
}


void GasNetwork::delCS() {
    int id;

    while (true) {
        std::cout << "input id(0 for exit): ";
        id = GetCorrectNumber(0, 10000);

        if (id == 0)
            break;

        if (!this->cssmap.contains(id))
            continue;

        if (this->cssmap.at(id).IsUsing())
            this->delete_GraphCS(this->cssmap.at(id));
    }
}
