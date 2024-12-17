#include "filters.h"
#include <string>
#include <iostream>
#include "menu.h"
#include "logging.h"
#include <format>
#include <chrono>
#include "GN.h"

using namespace std;
using namespace chrono;


void PrintMainMenu()
{
    cout << "Choose command" << endl;
    cout << "1. Working with pipes" << endl;
    cout << "2. Working with CS" << endl;
    cout << "3. Gas Network" << endl;
    cout << "4. Show all objects" << endl;
    cout << "5. Save" << endl;
    cout << "6. Download" << endl;
    cout << "7. Exit " << endl;
}

int main() {
    redirect_output_wrapper cerr_out(cerr);
    ofstream logfile("log.txt");
    if (logfile)
        cerr_out.redirect(logfile);

    GasNetwork gnet;


    int command;
    while (true) {
        PrintMainMenu();
        command = GetCorrectNumber(1, 7);
        switch (command) {
        case 1:
        {
            PipesMenu(gnet);
            break;
        }
   
        case 2:
        {
            CSMenu(gnet);
            break;
        }
        case 3:
        {
            GNetwork_menu(gnet);
            break;
        }
        case 4:
        {
            gnet.ShowAll();
            break;
        };
        case 5:
        {
            gnet.SaveAll();
            break;
        };
        
        case 6:
        {
            gnet.Download();
            break;
        };
        case 7:
        {
            return 0;
            break;
        }
        }
    }
    return 0;
}
