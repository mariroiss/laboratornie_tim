#pragma once
#include <unordered_set>
#include <unordered_map>
using namespace std;

void PrintPipesMenu();
void PipesMenu(unordered_map<int, Pipe>& pipesmap, std::unordered_set<int> &selected_pipes);

void PrintSelectedPipesMenu();
void SelectedPipesMenu(unordered_map<int, Pipe>& pipesmap, unordered_set<int>& selected_pipes);

void PrintFilterPipesMenu();
void FilterPipesMenu(unordered_map<int, Pipe>& pipesmap, unordered_set<int>& selected_pipes);

void PrintEditPipesMenu();
void EditPipesMenu(unordered_map<int, Pipe>& pipesmap, unordered_set<int>& selected_pipes);


void PrintCSMenu();
void CSMenu(unordered_map<int, CS>& cssmap, std::unordered_set<int>& selected_cs);

void PrintSelectedCSMenu();
void SelectedCSMenu(unordered_map<int, CS>& cssmap, unordered_set<int>& selected_cs);

void PrintFilterCSMenu();
void FilterCSMenu(unordered_map<int, CS>& cssmap, unordered_set<int>& selected_cs);

void PrintEditCSMenu();
void EditCSMenu(unordered_map<int, CS>& cssmap, unordered_set<int>& selected_cs);