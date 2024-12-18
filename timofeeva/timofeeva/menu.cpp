#include <iostream>
#include "menu.h"
#include <chrono>
#include <format>

using namespace std;


// pipe menu
void PrintPipesMenu() {
    cout << endl;
    cout << "Choose command" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Add pipe" << endl;
    cout << "2. Select pipes" << endl;
}


void PipesMenu(GasNetwork& gnet) {
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
            gnet.addPipe();
            break;
        }
       case 2:
        {
            SelectedPipesMenu(gnet);
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

void SelectedPipesMenu(GasNetwork& gnet) {
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
            FilterPipesMenu(gnet);
            break;
        }
        case 2:
        {
            gnet.PrintSelectedPipes();
            break;
        }
        case 3:
        {
            EditPipesMenu(gnet);
            break;
        }
        case 4:
        {
            gnet.selectPipesByID(1);
            break;
        }
        case 5:
        {
            gnet.clearSelectedPipes();
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

void FilterPipesMenu(GasNetwork& gnet) {
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
            gnet.selectAllpipes();
            return;
        }
        case 2:
        {
            gnet.selectPipesByID(0);
            return;
        }
        case 3:
        {
            gnet.Find_pipesByName();
            return;
        }
        case 4:
        {
            gnet.FindByIsWorking();
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

void EditPipesMenu(GasNetwork& gnet) {
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
            gnet.change_selectedPipes_workStatus();
            break;
        }
        case 2:
        {
            gnet.delete_selectedPipes();
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


void CSMenu(GasNetwork& gnet) {
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
            gnet.addCS();
            break;
        }
        case 2:
        {
            SelectedCSMenu(gnet);
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
    cout << "2. See selected cs" << endl;//
    cout << "3. Edit selected cs" << endl;
    cout << "4. Choose ids from selected" << endl;
    cout << "5. Remove from selected" << endl;
}

void SelectedCSMenu(GasNetwork& gnet) {
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
            FilterCSMenu(gnet);
            break;
        }
        case 2:
        {
            gnet.PrintSelectedCS();
            break;
        }
        case 3:
        {
            EditCSMenu(gnet);
            break;
        }
        case 4:
        {
            gnet.selectCSByID(1);
            break;
        }
        case 5:
        {
            gnet.clearSelectedCS();
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

void FilterCSMenu(GasNetwork& gnet) {
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
            gnet.selectAllcs();
            return;
        }
        case 2:
        {
            gnet.selectCSByID(0);
            return;
        }
        case 3:
        {
            gnet.Find_csByName();
            return;
        }
        case 4:
        {
            gnet.FindByUnusedWorkshops();
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

void EditCSMenu(GasNetwork& gnet) {
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
            gnet.EditCS();
            break;
        }
        case 2:
        {
            gnet.delete_selectedCS();
            break;
        }
        }
    }
    return;
}


// Gas Network
void print_GNetwork_menu() {
    cout << endl;
    cout << endl;
    cout << "Menu GTN\n";
    cout << "0 - back\n";
    cout << "1 - create graph\n";
    cout << "2 - print graph\n";
    cout << "3 - make TS\n";
    cout << "4 - edit GTN\n";
    cout << endl;
}

void GNetwork_menu(GasNetwork& gnet) {
    while (true) {
        print_GNetwork_menu();

        int choice = GetCorrectNumber(0, 4);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gnet.createGraph();
            
            break;
        case 2:
            gnet.showGraph();
            
            break;
        case 3:
            gnet.make_TS();
            break;
        case 4:
            edit_GNetwork_menu(gnet);
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}

void print_edit_GNetwork_menu() {
    cout << endl;
    cout << endl;
    cout << "Menu edit GTN\n";
    cout << "0 - back\n";
    cout << "1 - add node\n";
    cout << "2 - delete pipes\n";
    cout << "3 - delete CSs\n";
    cout << "4 - clear graph\n";
    cout << endl;
}

void edit_GNetwork_menu(GasNetwork& gnet) {
    while (true) {
        print_edit_GNetwork_menu();

        int choice = GetCorrectNumber(0, 4);

        switch (choice)
        {
        case 0:
            return;
        case 1:
            gnet.connect();
            break;
        case 2:
            gnet.delPipe();
            break;
        case 3:
            gnet.delCS();
            break;
        case 4:
            gnet.clearGraph();
            break;
        default:
            cout << "You choose the number, that not exist!\n";
            break;
        }
    }
}
