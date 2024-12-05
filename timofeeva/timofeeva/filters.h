#pragma once
#include "utils.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "pipe.h"
#include "cs.h"
#include <sstream>


using namespace std;
template<typename T, typename K>
using Filter = bool(*)(const T& obj, const K param);


bool CheckByIsWorking(const Pipe& pipe, const bool repair);
void FindByIsWorking(const unordered_map<int, Pipe>& pipes, unordered_set<int>& selected_pipes);
bool CheckByProcent(const CS& cs, const double percent_threshold);
void FindByUnusedWorkshops(const std::unordered_map<int, CS>& list_of_CSs, std::unordered_set<int>& selected_CSs);

/*
template<typename T>
unordered_set<int> SelectById(const T& map)
{
	unordered_set<int> res;
	int id;
	int num;
	num = map.size();
	while (true) {
		cout << "Enter the ID (0 for exit): ";
		id = GetCorrectNumber(0, num);
		if (id == 0)
			break;
		if (map.contains(id))
		{
			res.emplace(id);
		}
	}
	return res;
}  */

template<typename T>
std::unordered_set<int> SelectById(const T& set) {
	std::unordered_set<int> subset;
	int id;

	while (true) {
		std::cout << "input id(0 for exit): ";
		id = GetCorrectNumber<int>(0, 1000);

		if (id == 0) return subset;

		if (set.contains(id)) subset.emplace(id);
	}
}

template<typename T, typename K>
bool CheckByName(const T& obj, const K name) {
	return obj.GetName().find(name) != std::string::npos;
}


template<typename T, typename K>
void FindByFilter(const std::unordered_map<int, T>& obj, std::unordered_set<int>& selected_obj, Filter<T, K> func, const K param) {
	for (const auto& pair : obj) {
		if (func(pair.second, param)) {
			selected_obj.emplace(pair.first);
		}
	}
}

template<typename T>
void FindByName(const std::unordered_map<int, T>& set, std::unordered_set<int>& subset) {
	std::string name;
	std::cout << "Enter the name to search for: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	FindByFilter(set, subset, CheckByName, name);
}
/*
template<typename T>
void FindByName(const std::unordered_map<int, T>& obj, std::unordered_set<int>& selected_obj) {
	cout << "input name: ";
	string name;
	INPUT_LINE(std::cin, name);

	FindByFilter(obj, selected_obj, CheckByName, name);
}
*/
template<typename T>
void SelectAll(const unordered_map<int, T>& obj, unordered_set<int>& selected_obj) {
	for (const auto& pair : obj) {
		selected_obj.emplace(pair.first);
	}
}
/*
template<typename T>
void delete_selectedObj(unordered_map<int, T>& obj, unordered_set<int>& selected_obj) {
	for (auto it = selected_obj.begin(); it != selected_obj.end();) {
		erase_obj(obj, *it);
		it = selected_obj.erase(it);
	}
	cout << " objects was erased!" << std::endl;
}*/

