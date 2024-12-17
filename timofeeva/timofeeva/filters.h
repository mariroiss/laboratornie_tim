#pragma once
#include <string>
#include <sstream>
#include "GN.h"

using namespace std;


template<typename T>
std::unordered_set<int> GasNetwork::SelectById(const T& set) {
	std::unordered_set<int> subset;
	int id;

	while (true) {
		std::cout << "Enter the ID  (0 for exit): ";
		id = GetCorrectNumber<int>(0, 1000);

		if (id == 0) return subset;

		if (set.contains(id)) subset.emplace(id);
	}
}

template<typename T, typename K>
bool GasNetwork::CheckByName(const T& obj, const K& name) {
	return obj.GetName().find(name) != std::string::npos;
}


template<typename T, typename K>
void GasNetwork::FindByFilter(const std::unordered_map<int, T>& obj, std::unordered_set<int>& selected_obj, Filter<T, K> func, const K param) {
	for (const auto& pair : obj) {
		if ((this->*func)(pair.second, param)) {
			selected_obj.emplace(pair.first);
		}
	}
}


template<typename T>
void delete_selectedObj(unordered_map<int, T>& obj, unordered_set<int>& selected_obj) {
	for (auto it = selected_obj.begin(); it != selected_obj.end();) {
		erase_obj(obj, *it);
		it = selected_obj.erase(it);
	}
	cout << " objects was erased!" << std::endl;
}

