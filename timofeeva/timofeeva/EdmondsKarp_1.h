//#pragma once
//#include <unordered_map>
//#include <unordered_set>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <limits>
//#include "GN.h"
//
//
//template<typename T>
//bool GasNetwork::bfs(T s, T t, std::unordered_map<T, T>& parent, std::unordered_map<T, std::unordered_map<T, int>>& capacity) {
//    std::unordered_set<T> visited;
//    std::queue<T> q;
//    q.push(s);
//    visited.insert(s);
//
//    while (!q.empty()) {
//        T u = q.front(); // Get the front element (no reference is needed for T)
//        q.pop();
//
//        if (graph.count(u) == 0) continue;
//
//        for (const auto& v : this->graph.at(u)) {
//            if (visited.find(v) == visited.end() && capacity[u][v] > 0) {
//                visited.insert(v);
//                parent[v] = u;
//                if (v == t) {
//                    return true;
//                }
//                q.push(v);
//            }
//        }
//    }
//    return false;
//}
//
//
//template<typename T>
//int GasNetwork::edmondsKarp(const T& source, const T& sink) {
//
//    std::unordered_map<T, std::unordered_map<T, int>> capacity;
//
//    for (const auto& pair : graph) {
//        for (auto& v : pair.second) {
//            capacity[pair.first][v] = this->getSUMproductivity(pair.first, v);
//        }
//    }
//
//
//    std::unordered_map<T, T> parent;
//    int maxFlow = 0;
//
//
//    while (this->bfs(source, sink, parent, capacity)) {
//        int pathFlow = std::numeric_limits<int>::max(); // Initialize pathFlow to max int
//
//
//        //Find Minimum Capacity
//        for (auto v = sink; v != source; v = parent[v]) {
//            if (parent.count(v) == 0) break;
//            auto u = parent[v];
//            pathFlow = std::min(pathFlow, capacity[u][v]);
//        }
//
//        //Update Residual Capacities
//        for (auto v = sink; v != source; v = parent[v]) {
//            if (parent.count(v) == 0) break;
//            auto u = parent[v];
//            capacity[u][v] -= pathFlow;
//            capacity[v][u] += pathFlow;
//        }
//
//        maxFlow += pathFlow;
//        parent.clear(); // clear parent for next bfs
//    }
//
//
//    this->maxFlow_path = this->getMAXFlowPath(source, sink, parent);
//    return maxFlow;
//}
//
//
//template<typename T>
//std::vector<T> GasNetwork::getMAXFlowPath(const T& source, const T& sink, std::unordered_map<T, T>& parent) {
//    std::vector<T> path;
//    T v = sink;
//
//    while (v != source) {
//        path.push_back(v);
//        if (parent.count(v) == 0) break;
//        v = parent[v];
//    }
//    path.push_back(source);
//
//    reverse(path.begin(), path.end());
//    return path;
//}



#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
#include "GN.h"


template<typename T>
bool GasNetwork::bfs(T s, T t, std::unordered_map<T, T>& parent, std::unordered_map<T, std::unordered_map<T, int>>& capacity) {
    std::unordered_set<T> visited;
    std::queue<T> q;
    q.push(s);
    visited.insert(s);

    while (!q.empty()) {
        T u = q.front();
        q.pop();

        if (graph.count(u) == 0) continue;

        for (const auto& v : this->graph.at(u)) {
            if (visited.find(v) == visited.end() && capacity[u][v] > 0) {
                visited.insert(v);
                parent[v] = u;
                if (v == t) {
                    return true;
                }
                q.push(v);
            }
        }
    }
    return false;
}


template<typename T>
int GasNetwork::edmondsKarp(const T& source, const T& sink) {

    std::unordered_map<T, std::unordered_map<T, int>> capacity;

    for (const auto& pair : graph) {
        for (auto& v : pair.second) {
            capacity[pair.first][v] = this->getSUMproductivity(pair.first, v);
        }
    }

    std::unordered_map<T, T> parent;
    int maxFlow = 0;
    std::vector<T> pathVertices;


    while (this->bfs(source, sink, parent, capacity)) {
        int pathFlow = std::numeric_limits<int>::max();

        for (auto v = sink; v != source; v = parent[v]) {
            if (parent.count(v) == 0) break;
            auto u = parent[v];
            pathFlow = std::min(pathFlow, capacity[u][v]);

        }
        for (auto v = sink; v != source; v = parent[v]) {
            if (parent.count(v) == 0) break;
            auto u = parent[v];
            capacity[u][v] -= pathFlow;
            capacity[v][u] += pathFlow;
        }


        maxFlow += pathFlow;

        pathVertices.clear();

        T v = sink;
        while (v != source) {
            pathVertices.push_back(v);
            if (parent.count(v) == 0) break;
            v = parent[v];
        }
        pathVertices.push_back(source);
        std::reverse(pathVertices.begin(), pathVertices.end());

        parent.clear();

    }


    this->maxFlow_path = pathVertices;
    return maxFlow;
}

template<typename T>
std::vector<T> GasNetwork::getMAXFlowPath(const T& source, const T& sink, std::unordered_map<T, T>& parent) {
    std::vector<T> path;
    T v = sink;

    while (v != source) {
        path.push_back(v);
        if (parent.count(v) == 0) break;
        v = parent[v];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());
    return path;
}


