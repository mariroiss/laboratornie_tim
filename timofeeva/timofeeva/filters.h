#pragma once
#include "utils.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "pipe.h"

using namespace std;
template<typename T, typename P>
using Filter = bool(*)(T& val, P param);

template<typename T>
bool checkByName(T& val, string name)
{
	size_t pos = val.getname().find(name);
	if (pos != string::npos) return true;
	else return false;
}

//bool checkbyrepair(Pipe& p, bool status);
//bool checkByWSInWork(CS& cs, double percent);

template<typename T, typename P>
unordered_set<int> findfilter(unordered_map<int, T>& map, Filter<T, P> f, P param)
{
	unordered_set<int> res;
	int i = 0;
	for (auto& [id, val] : map)
	{
		if (f(val, param))
			res.emplace(id);
	}
	return res;
}


template<typename T>
unordered_set<int> SelectById(const T& map)
{
	unordered_set<int> res;
	int id;
	int num;
	num = map.size();
	while (true) {
		cout << "Enter the ID of pipes (0 for exit): ";
		id = GetCorrectNumber(0, num);
		if (id == 0)
			break;
		if (map.contains(id))
		{
			res.emplace(id);
		}
	}
	return res;
}  

template<typename T>
void EditPipebyId(unordered_map<int, T>& map)
{
	unordered_set<int> res;
	res = SelectById(map);
	if (res.size() != 0)
	{
		for (const int& id : res) {
			map.find(id)->second.ChangeRepair();
		}
		cout << "Repair status has been changed" << endl;
	}
	else
	{
		cout << "No pipes" << endl;
	}
}



template<typename T>
void EditCSbyId(unordered_map<int, T>& cssmap) {
	int cs_id;

	if (cssmap.empty()) {
		cout << "No CSS" << std::endl;
		return;
	}

	while (true) {
		cout << "Enter the ID of css (0 to exit): ";
		cs_id = GetCorrectNumber(0, numeric_limits<int>::max()); 
		if (cs_id == 0) break;

		if (cssmap.count(cs_id) == 1) {
			int numWorkshops = cssmap[cs_id].GetNumberofWorkshops();
			int new_act;
			while (true) {
				cout << "Enter new number of active workshops (0 to exit, 0 to " << numWorkshops << "): ";
				new_act = GetCorrectNumber(0, numWorkshops);
				if (new_act >= 0 && new_act <= numWorkshops) {
					cssmap[cs_id].SetNumberofActiveWorkshops(new_act);
					cout << "Number of active workshops updated to: " << new_act << endl;
					break; 
				}
				else {
					cout << "Enter the number of active workshops from 0 to " << numWorkshops << endl;
				}
			}
		}
		else {
			cout << "No CS with this ID" << std::endl;
		}
	}
}

