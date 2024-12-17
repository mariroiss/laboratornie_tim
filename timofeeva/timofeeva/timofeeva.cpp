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
    cout << "3. Show all objects" << endl;
    cout << "4. Save" << endl;
    cout << "5. Download" << endl;
    cout << "6. Exit " << endl;
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
        command = GetCorrectNumber(1, 6);
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
            gnet.ShowAll();
            break;
        };
        case 4:
        {
            gnet.SaveAll();
            break;
        };
        
        case 5:
        {
            gnet.Download();
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
