#pragma once
#include <iostream>
#include "pipe.h"
#include "cs.h"
#include <unordered_map>   
#include <unordered_set>
#include <string>



using namespace std;

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
    //cerr << value << endl;
    return value;
}

template<typename T>
void load(ifstream& file, unordered_map<int, T>& map)
{
    T object(file);
    map.emplace(object.GetId(), object);
}

template<typename T>
void PrintSelected(const unordered_map<int, T>& obj, const unordered_set<int>& selected_obj) {
    if (selected_obj.size() == 0) cout << "No selected!" << endl;

    for (const int& id : selected_obj) {
        cout << obj.find(id)->second << endl;
    }
}

void SaveAll(unordered_map<int, Pipe>& pipemap, unordered_map<int, CS>& cssmap);
void ShowAll(unordered_map<int, Pipe> pipemap, unordered_map<int, CS> cssmap);
void Download(unordered_map<int, Pipe>& pipemap, unordered_map<int, CS>& csmap);


