#include <iostream>
#include "pipe.h"
#include "cs.h"
#include "menu.h"
#include "utils.h"
// #include "logger.h"
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <format>
#include "filters.h"


using namespace std;

// pipe menu
void PrintPipesMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add pipe" << endl;
    cout << "2. Select pipes" << endl;
}


void PipesMenu(unordered_map<int, Pipe>& pipesmap, unordered_set<int> &selected_pipes) {
    while (true) {
        PrintPipesMenu();
        int command = GetCorrectNumber(0,2);

        switch (command)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            Pipe p;
            p.AddPipe();
            pipesmap.emplace(p.GetId(), p);
            break;
        }
       case 2:
        {
            SelectedPipesMenu(pipesmap, selected_pipes);
            break;
        }
        }
    }
    return;
}

void PrintSelectedPipesMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Filter" << endl;
    cout << "2. See selected pipes" << endl;
    cout << "3. Edit selected pipes" << endl;
    cout << "4. Choose ids from selected" << endl;
    cout << "5. Remove from selected" << endl;
}

void SelectedPipesMenu(unordered_map<int, Pipe>& pipesmap, unordered_set<int>& selected_pipes) {
    while (true) {
        PrintSelectedPipesMenu();
        int command = GetCorrectNumber(0,5);

        switch (command)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            FilterPipesMenu(pipesmap, selected_pipes);
            break;
        }
        case 2:
        {
            //PrintSelected(pipesmap, selected_pipes);
            break;
        }
        case 3:
        {
            EditPipesMenu(pipesmap, selected_pipes);
            break;
        }
        case 4:
        {
            selected_pipes = SelectById(selected_pipes);
            break;
        }
        case 5:
        {

            break;
        }
        }
    }
    return;
}

void PrintFilterPipesMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Selected all pipes" << endl;
    cout << "2. Selected by id" << endl;
    cout << "3. Selected by name" << endl;
    cout << "4. Selected by repair status" << endl;
}

void FilterPipesMenu(unordered_map<int, Pipe>& pipesmap, unordered_set<int>& selected_pipes) {
    while (true) {
        PrintFilterPipesMenu();
        int command = GetCorrectNumber(0,4);

        switch (command)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        }
    }
    return;
}

void PrintEditPipesMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Change repair status for selected pipes" << endl;
    cout << "2. Delete selected pipes" << endl;
}

void EditPipesMenu(unordered_map<int, Pipe>& pipesmap, unordered_set<int>& selected_pipes) {
    while (true) {
        PrintEditPipesMenu();
        int command = GetCorrectNumber(0,2);

        switch (command)
        {
        case 0:
        {
            return;
        }
        case 1:
        {

            break;
        }
        case 2:
        {

            break;
        }
        }
    }
    return;
}




//cs menu
void PrintCSMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add CS" << endl;
    cout << "2. Select CSs" << endl;
}


void CSMenu(unordered_map<int, CS>& cssmap, unordered_set<int>& selected_cs) {
    while (true) {
        PrintCSMenu();
        int command = GetCorrectNumber(0,2);

        switch (command)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            CS c;
            c.AddCS();
            cssmap.emplace(c.GetId(), c);
            break;
        }
        case 2:
        {
            SelectedCSMenu(cssmap, selected_cs);
            break;
        }
        }
    }
    return;
}

void PrintSelectedCSMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Filter" << endl;
    cout << "2. See selected cs" << endl;
    cout << "3. Edit selected cs" << endl;
    cout << "4. Choose ids from selected" << endl;
    cout << "5. Remove from selected" << endl;
}

void SelectedCSMenu(unordered_map<int, CS>& cssmap, unordered_set<int>& selected_cs) {
    while (true) {
        PrintSelectedCSMenu();
        int command = GetCorrectNumber(0,5);

        switch (command)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            FilterCSMenu(cssmap, selected_cs);
            break;
        }
        case 2:
        {
            //PrintSelected(pipesmap, selected_pipes);
            break;
        }
        case 3:
        {
            EditCSMenu(cssmap, selected_cs);
            break;
        }
        case 4:
        {
            selected_cs = SelectById(selected_cs);
            break;
        }
        case 5:
        {

            break;
        }
        }
    }
    return;
}

void PrintFilterCSMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Selected all cs" << endl;
    cout << "2. Selected by id" << endl;
    cout << "3. Selected by name" << endl;
    cout << "4. Selected by unused workshops" << endl;
}

void FilterCSMenu(unordered_map<int, CS>& cssmap, unordered_set<int>& selected_cs) {
    while (true) {
        PrintFilterCSMenu();
        int command = GetCorrectNumber(0,4);

        switch (command)
        {
        case 0:
        {
            return;
        }
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        }
    }
    return;
}

void PrintEditCSMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Change number of active workshops" << endl;
    cout << "2. Delete selected cs" << endl;
}

void EditCSMenu(unordered_map<int, CS>& cssmap, unordered_set<int>& selected_cs) {
    while (true) {
        PrintEditCSMenu();
        int command = GetCorrectNumber(0,2);

        switch (command)
        {
        case 0:
        {
            return;
        }
        case 1:
        {

            break;
        }
        case 2:
        {

            break;
        }
        }
    }
    return;
}