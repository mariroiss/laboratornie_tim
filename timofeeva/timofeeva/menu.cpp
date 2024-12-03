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


using namespace std;

// pipe menu
void PrintPipesMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "1. Add pipe" << endl;
    cout << "2. Edit pipe" << endl; //по id
    cout << "3. Delete all pipes" << endl;//удалить все трубы
    cout << "4. Pipe filter" << endl;
    cout << "5. Exit" << endl;
}//фильтр по имени иои статусу -> удалить или поменять статус 


void PipesMenu(unordered_map<int, Pipe>& pipesmap) {
    while (true) {
        PrintPipesMenu();
        int command = GetCorrectNumber(1,5);

        switch (command)
        {
        case 1:
        {
            Pipe p;
            p.AddPipe();
            pipesmap.emplace(p.GetId(), p);
            break;
        }
       case 2:
        {
            //EditPipebyId(pipesmap);
            break;
        }
        case 3:
        {
            //DeletePipebyId(pipesmap);
            break;
        }
        case 4:
        {
            //DeletePipebyId(pipesmap);
            break;
        }
        case 5:
        {
            return;
            break;
        }
        /*default:
            cout << "You choose the number, that not exist!\n";
            break;*/
        }
    }
    return;
}


//cs menu
void PrintCSMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "1. Add cs" << endl;
    cout << "2. Edit cs" << endl; //по id
    cout << "3. Delete all cs" << endl;//удалить все трубы
    cout << "4. CS filter" << endl;
    cout << "5. Exit" << endl;
}//фильтр по имени иои статусу -> удалить или поменять статус 


void CSMenu(unordered_map<int, CS>& cssmap) {
    while (true) {
        PrintCSMenu();
        int command = GetCorrectNumber(1, 5);

        switch (command)
        {
        case 1:
        {
            CS c;
            c.AddCS();
            cssmap.emplace(c.GetId(), c);
            break;
        }
        case 2:
        {
            //EditCSbyId(cssmap);
            break;
        }
        case 3:
        {
            //DeleteCSbyId(cssmap);
            break;
        }
        case 5:
        {
            return;
            break;
        }
        }
    }
    return;
}
