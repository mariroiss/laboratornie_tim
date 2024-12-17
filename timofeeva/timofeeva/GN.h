#pragma once
#include <unordered_map>
#include <unordered_set>
#include "pipe.h"
#include "cs.h"
#include "utils.h"


class GasNetwork {
private:
    template<typename T, typename K>
    using Filter = bool(GasNetwork::*)(const T& obj, const K& param);

    std::unordered_map<int, std::unordered_set<int>> graph;
    std::vector<int> TSorder;

    std::unordered_map<int, Pipe> pipesmap;
    std::unordered_set<int> selected_pipes;

    std::unordered_map<int, CS> cssmap;
    std::unordered_set<int> selected_cs;
public:
    void ShowAll();
    void SaveAll();
    void Download();
    void clearSelectedPipes();
    void clearSelectedCS();

    void delete_GraphPipe(Pipe& pipe);
    void delete_GraphCS(CS& cs);

    void delPipe();
    void delCS();

    void showGraph() const;
    void clearGraph();

    void createGraph();
    bool connect();

    bool make_TS();



    template<typename T, typename K>
    bool CheckByName(const T& obj, const K& name);

    bool CheckByIsWorking(const Pipe& pipe, const bool& repair);

    bool CheckByProcent(const CS& cs, const double& percent_threshold);

    bool CheckByDia(const Pipe& pipe, const int& dia);

    template<typename T, typename K>
    void FindByFilter(const std::unordered_map<int, T>& obj, std::unordered_set<int>& selected_obj, Filter<T, K> func, const K param);

    template<typename T>
    std::unordered_set<int> SelectById(const T& set);

    template<typename T>
    void erase_obj(std::unordered_map<int, T>& objs, const int id);

    void change_selectedPipes_workStatus();
    void load(ifstream& file, std::unordered_map<int, Pipe>& map);
    void PrintSelectedPipes();
    void addPipe();
    void selectPipesByID(const int& choice);
    void selectAllpipes();
    void Find_pipesByName();
    void FindByIsWorking();
    void delete_selectedPipes();
    int FindByDiameter(const int& diameter);

    void EditCS();
    void load(ifstream& file, std::unordered_map<int, CS>& map);
    void PrintSelectedCS();
    void addCS();
    void selectCSByID(const int& choice);
    void selectAllcs();
    void Find_csByName();
    void FindByUnusedWorkshops();
    void delete_selectedCS();
};
