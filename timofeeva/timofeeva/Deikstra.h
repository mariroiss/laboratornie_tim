#pragma once
#include "GN.h"
#include <queue>


template<typename T>
std::vector<T> GasNetwork::metodDeikstra(T StartNode, T EndNode) {
	std::unordered_map<T, int> dist;
	std::unordered_map<T, T> prev;
	std::unordered_set<T> visited;


    for (const auto& pair : this->graph) {
        dist[pair.first] = this->INF;
    }
    dist[StartNode] = 0;

    std::priority_queue<std::pair<int, T>, std::vector<std::pair<int, T>>, std::greater<std::pair<int, T>>> pq;
    pq.push({0, StartNode});

	while (!pq.empty()) {
		T u = pq.top().second;
		pq.pop();

		if (u == EndNode) { break; }

		visited.insert(u);

        for (const auto& v : this->graph.at(u)) {
            if (visited.find(v) == visited.end()) {
                int weight = this->getMINDistance(u, v);
                if (weight != this->INF && dist[u] != this->INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    prev[v] = u;
                    pq.push({dist[v], v});
                }
            }
		}
	}

    std::vector<T> path;
    T current_node = EndNode;
    while (current_node != StartNode) {
        path.push_back(current_node); 
        if (prev.find(current_node) != prev.end()) {
            current_node = prev[current_node];
        } else {
            return std::vector<T>();
        }
    }
	
    path.push_back(StartNode);
    reverse(path.begin(), path.end());
    return path;
}
