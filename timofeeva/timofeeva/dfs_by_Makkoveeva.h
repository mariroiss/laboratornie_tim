#pragma once
#include <unordered_map>
#include <unordered_set>
#include<vector>
#include <iostream>
#include <string>
#include<stack>


template <typename T>
std::vector<T> dfs_by_Makkoveeva(std::unordered_map<T, std::unordered_set<T>> &graph) 
{
	std::vector<T>sortedgraph;
	std::unordered_map<T, int>visited;
	std::vector<T>stack;
	bool cycle = false;
	for (auto& pair:graph)
	{
		const T& node=pair.first;
		if (visited[node] == 0)
		{
			stack.push_back(node);
			while (!stack.empty()&&!cycle)
			{
				T currentnode = stack.back();
				stack.pop_back();
				if (visited[currentnode] == 0)
				{
					visited[currentnode] = 1;
					stack.push_back(currentnode);
					for (const T& neighbor : graph[currentnode])
					{
						if (visited[neighbor] == 0)
						{
							stack.push_back(neighbor);
						}
						else if (visited[neighbor]==1)
						{
							cycle=true;
							break;
						}
					}
				}
				else if (visited[currentnode] == 1)
				{
					visited[currentnode] = 2;
					sortedgraph.push_back(currentnode);
				}
			}
			if (cycle)
			{
				return { };
			}
		}
	}
	reverse(sortedgraph.begin(),sortedgraph.end());
	return sortedgraph;
}
