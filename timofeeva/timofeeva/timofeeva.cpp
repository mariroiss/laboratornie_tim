#include "pipe.h"
#include "cs.h"
#include "utils.h"
//#include "filters.h"
#include <string>
#include <iostream>
#include <unordered_map>
#include "menu.h"



using namespace std;


/*int main()
{
    unordered_map<int, PIPE> pipemap;
    unordered_map<int, CS> csmap;

    while (1)
    {
        cout << "\nChoose command" << endl
            << "1. Change pipe" << endl
            << "2. Change cs" << endl
            << "3. Show all objects" << endl
            << "4. Download" << endl
            << "5. Save" << endl
            << "6. Exit " << endl;

        int option = GetCorrectNumber(1, 8);
        switch (option)
        {
        case 1:
        {
            pipe_menu(pipemap);
            break;
        }
        case 2:
        {
            cs_menu(csmap);
            break;
        }
        case 3:
        {
            showall(pipemap, csmap);
            break;
        }
        case 5:
        {
            save(pipemap, csmap);
            break;
        }
        case 0:
        {
            return 0;
        }
        }

    }

}*/

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
    unordered_map<int, CS> cssmap; 

    int command;
    while (true) {
        PrintMainMenu();
        command = GetCorrectNumber(1, 6);
        switch (command) {
        case 1:
        {
            PipesMenu(pipesmap);
            break;
        }
   
        case 2:
        {
            CSMenu(cssmap);
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
        /*
        case 5:
        {
            LoadAll(pipesmap, cssmap, pipesmap_selected, cssmap_selected);
            break;
        };*/
        case 6:
        {
            return 0;
            break;
        }
        /*default:
            cout << "You choose the number, that not exist!\n";
            break;*/
        }
    }
    return 0;
}