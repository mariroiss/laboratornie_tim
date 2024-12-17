#include "filters.h"

using namespace std;


bool GasNetwork::CheckByIsWorking(const Pipe& pipe, const bool& repair) {
    return pipe.GetRepair() == repair;
}

void GasNetwork::FindByIsWorking() {
    cout << "Enter repair sratus ";
    int work_status = GetCorrectNumber<int>(0, 1);

    this->FindByFilter<Pipe, bool>(this->pipesmap, this->selected_pipes, &GasNetwork::CheckByIsWorking, work_status);
}

bool GasNetwork::CheckByProcent(const CS& cs, const double& percent_threshold) {
    if (cs.GetNumberofWorkshops() == 0) return false;
    double non_operating_percentage = ((cs.GetNumberofWorkshops() - cs.GetNumberofActiveWorkshops()) / static_cast<double>(cs.GetNumberofWorkshops())) * 100.0;
    return non_operating_percentage > percent_threshold;
}


void GasNetwork::FindByUnusedWorkshops() {
    cout << "Enter the minimum percentage of non-operating workshops: ";
    double percent_threshold = GetCorrectNumber<double>(0.0, 100.0);

    this->FindByFilter<CS, double>(this->cssmap, this->selected_cs, &GasNetwork::CheckByProcent, percent_threshold);
}


void GasNetwork::Find_pipesByName() {
    cout << "input name: ";
    string name;
    INPUT_LINE(std::cin, name);

    this->FindByFilter(this->pipesmap, this->selected_pipes, &GasNetwork::CheckByName, name);
}


void GasNetwork::Find_csByName() {
    cout << "input name: ";
    string name;
    INPUT_LINE(std::cin, name);

    this->FindByFilter(this->cssmap, this->selected_cs, &GasNetwork::CheckByName, name);
}


void GasNetwork::selectPipesByID(const int& choice) {
    if (!choice)
        this->selected_pipes = this->SelectById(this->pipesmap);
    else
        this->selected_pipes = this->SelectById(this->selected_pipes);
}


void GasNetwork::selectCSByID(const int& choice) {
    if (!choice)
        this->selected_cs = this->SelectById(this->cssmap);
    else
        this->selected_cs = this->SelectById(this->cssmap);
}


void GasNetwork::selectAllpipes() {
    for (const auto& pair : this->pipesmap) {
        this->selected_pipes.emplace(pair.first);
    }
}


void GasNetwork::selectAllcs() {
    for (const auto& pair : this->cssmap) {
        this->selected_cs.emplace(pair.first);
    }
}


bool GasNetwork::CheckByDia(const Pipe& pipe, const int& dia) {
    return pipe.get_diameter() == dia;
}

int GasNetwork::FindByDiameter(const int& diameter) {
    for (const auto& [id, pipe] : this->pipesmap) {
        if (!pipe.IsUsing() && this->CheckByDia(pipe, diameter)) return pipe.GetId();
    }

    Pipe pipe(diameter);
    this->pipesmap.emplace(pipe.GetId(), pipe);

    return pipe.GetId();
}
