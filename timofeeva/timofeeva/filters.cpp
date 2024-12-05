#include "filters.h"
#include "cs.h"
#include "pipe.h"
#include <unordered_map>

using namespace std;

bool CheckByIsWorking(const Pipe& pipe, const bool repair) {
    return pipe.GetRepair() == repair;
}


void FindByIsWorking(const std::unordered_map<int, Pipe>& pipes, std::unordered_set<int>& selected_pipes) {
    cout << "Enter repair sratus ";
    int work_status = GetCorrectNumber<int>(0, 1);

    FindByFilter<Pipe, bool>(pipes, selected_pipes, CheckByIsWorking, work_status);
}

bool CheckByProcent(const CS& cs, const double percent_threshold) {
    if (cs.GetNumberofWorkshops() == 0) return false;
    double non_operating_percentage = ((cs.GetNumberofWorkshops() - cs.GetNumberofActiveWorkshops()) / static_cast<double>(cs.GetNumberofWorkshops())) * 100.0;
    return non_operating_percentage > percent_threshold;
}


void FindByUnusedWorkshops(const std::unordered_map<int, CS>& list_of_CSs, std::unordered_set<int>& selected_CSs) {
    cout << "Enter the minimum percentage of non-operating workshops: ";
    double percent_threshold = GetCorrectNumber<double>(0.0, 100.0);

    FindByFilter<CS, double>(list_of_CSs, selected_CSs, CheckByProcent, percent_threshold);
}