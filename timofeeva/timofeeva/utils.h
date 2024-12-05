#pragma once
#include <iostream>
#include "pipe.h"
#include "cs.h"
#include <unordered_map>   
#include <unordered_set>
#include <typeinfo>
#include <string>
using namespace std;

#define INPUT_LINE(in, str) in.ignore(1000, '\n'); \
                            getline(in>>std::ws, str); \
                            std::cerr << str << std::endl;

#define CLEAR_SELECTED(selected) selected.clear(); \
                                std::cout << "Selected cleared!" << std::endl;

template <typename T>
T GetCorrectNumber(T min, T max)
{
    T value;
    while ((cin >> value).fail()
        || cin.peek() != '\n'
        || value < min || value > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nEnter a right number from " << min << " to " << max << "\n ";
    }
    cerr << value << endl;
    return value;
}

template<typename T>
void load(ifstream& file, unordered_map<int, T>& map)
{
    T object(file);
    map.emplace(object.GetId(), object);
}

template<typename T>
void PrintSelected(const std::unordered_map<int, T>& set, const std::unordered_set<int>& subset) {
    if (set.empty()) {
        std::cout << "No selected items." << std::endl;
    }
    else {
        for (const int& id : subset) {
            auto it = set.find(id);
            if (it != set.end()) {
                it->second.Show();
            }
        }
    }
}

template<typename T>
int Get_maxid(const std::unordered_map<int, T>& objs) {
    int id = 0;
    for (auto& [k, v] : objs) {
        if (k > id) id = k;
    }
    return id;
}

void SaveAll(unordered_map<int, Pipe>& pipemap, unordered_map<int, CS>& cssmap);
void ShowAll(unordered_map<int, Pipe> pipemap, unordered_map<int, CS> cssmap);
void Download(std::unordered_map<int, Pipe>& pipesmap, std::unordered_map<int, CS>& cs, std::unordered_set<int>& selected_pipe, std::unordered_set<int>& selected_cs);
void change_selectedPipes_workStatus(unordered_map<int, Pipe>& pipes, const unordered_set<int>& selected_pipes);
void EditCS(unordered_map<int, CS>& cssmap, const unordered_set<int>& selected_cs);

template<typename T>
void erase_obj(std::unordered_map<int, T>& objs, const int id) {
    if (objs.count(id)) {
        objs.erase(id);
    }
    else {
        std::cout << "There is not object with id " << id << std::endl;
    }
}
