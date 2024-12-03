#include "pipe.h"
#include "cs.h"
#include "utils.h"
#include "filters.h"
#include <string>
#include <iostream>
#include <unordered_map>


using namespace std;


int main()
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

}