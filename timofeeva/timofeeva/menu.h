#pragma once
#include <unordered_set>
#include <unordered_map>
using namespace std;

void PrintMainMenu();

void PrintPipesMenu();
void PipesMenu(unordered_map<int, Pipe>& pipesmap);

void PrintCSMenu();
void CSMenu(unordered_map<int, CS>& cssmap);