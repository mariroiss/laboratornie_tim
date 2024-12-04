#include "pipe.h"
#include "cs.h"
#include "utils.h"
//#include "filters.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include "menu.h"



using namespace std;


void PrintMainMenu()
{
    cout << "Choose command" << endl;
    cout << "1. Working with pipes" << endl;
    cout << "2. Working with CS" << endl;
    cout << "3. Show all objects" << endl;
    cout << "4. Save" << endl;
    cout << "5. Download" << endl;
    cout << "6. Exit " << endl;
}

int main() {
    unordered_map<int, Pipe> pipesmap;
    unordered_set<int> selected_pipes;

    unordered_map<int, CS> cssmap; 
    unordered_set<int> selected_cs;

    int command;
    while (true) {
        PrintMainMenu();
        command = GetCorrectNumber(1, 6);
        switch (command) {
        case 1:
        {
            PipesMenu(pipesmap, selected_pipes);
            break;
        }
   
        case 2:
        {
            CSMenu(cssmap, selected_cs);
            break;
        }
        case 3:
        {
            ShowAll(pipesmap, cssmap);
            break;
        };
        case 4:
        {
            SaveAll(pipesmap, cssmap);
            break;
        };
        
        case 5:
        {
            Download(pipesmap, cssmap, selected_pipes, selected_cs);
            break;
        };
        case 6:
        {
            return 0;
            break;
        }
        }
    }
    return 0;
}