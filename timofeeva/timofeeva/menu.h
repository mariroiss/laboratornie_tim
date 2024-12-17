#pragma once
#include "GN.h"

using namespace std;

void PrintPipesMenu();
void PipesMenu(GasNetwork& gnet);

void PrintSelectedPipesMenu();
void SelectedPipesMenu(GasNetwork& gnet);

void PrintFilterPipesMenu();
void FilterPipesMenu(GasNetwork& gnet);

void PrintEditPipesMenu();
void EditPipesMenu(GasNetwork& gnet);


void PrintCSMenu();
void CSMenu(GasNetwork& gn);

void PrintSelectedCSMenu();
void SelectedCSMenu(GasNetwork& gnet);

void PrintFilterCSMenu();
void FilterCSMenu(GasNetwork& gnet);

void PrintEditCSMenu();
void EditCSMenu(GasNetwork& gnet);


void print_GNetwork_menu();
void GNetwork_menu(GasNetwork& gnet);

void print_edit_GNetwork_menu();
void edit_GNetwork_menu(GasNetwork& gnet);
