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

    const int INF = std::numeric_limits<int>::max();

    std::unordered_map<int, std::unordered_set<int>> graph;
    std::vector<int> TSorder;

    std::vector<int> min_path;
    std::vector<int> maxFlow_path;
    int maxFlow;

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
    void showGraph();
    void clearGraph();
    void createGraph();
    bool connect();
    bool make_TS();

    std::unordered_set<int> get_IncidentPipes(const int& id_1, const int& id_2);
    int getMINDistance(const int& id_1, const int& id_2);

    template<typename T>
    std::vector<T> metodDeikstra(T StartNode, T EndNode);
    void displayMinimumPath();
    void calculateMinimumDistance();

    template<typename T>
    bool bfs(T s, T t, std::unordered_map<T, T>& parent, std::unordered_map<T, std::unordered_map<T, int>>& capacity);

    template<typename T>
    int edmondsKarp(const T& source, const T& sink);

    template<typename T>
    std::vector<T> getMAXFlowPath(const T& source, const T& sink, std::unordered_map<T, T>& parent);

    int getSUMproductivity(const int& id_1, const int& id_2);
    void show_maxFlow();
    void count_maxFlow();

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
