#include <iostream> 
#include <fstream> 
using namespace std;

struct Pipe {
    string NamePipe = "None";
    float Length = 0.0;
    int Diameter = 0;
    bool Repair = false;
};

struct Station
{
    string NameStation = "None";
    int NumberWorkshops = 0;
    int ActiveWorkshops = 0;
    float Effectivness = 0;
};

int check_int(int& int_data)

{
    cin >> int_data;
    while (cin.fail() || cin.peek() != '\n' || int_data <= 0)

    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter an int type > 0\n";
        cin >> int_data;
    }
    return int_data;
}
float check_float(float& float_data)
{
    cin >> float_data;
    while (cin.fail() || cin.peek() != '\n' || float_data <= 0)

    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter a float type > 0\n";
        cin >> float_data;

    }
    return float_data;

}


float check2_float(float& Effectivness)

{
    cin >> Effectivness;
    while (cin.fail() || cin.peek() != '\n' || (Effectivness < 0) || (Effectivness > 5))
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter a efficiency data from 0 to 5\n";
        cin >> Effectivness;

    }

    return Effectivness;
}

bool check_bool(bool& bool_data)

{
    cin >> bool_data;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter a bool type\n";
        cin >> bool_data;

    }
    return bool_data;
}

Pipe AddPipe()

{
    Pipe NewPipe;
    cout << endl << "Creating a new pipe" << endl;
    cout << "Enter the name of the pipe: ";
    cin >> NewPipe.NamePipe;

    cout << "Enter the length of the pipe: ";
    check_float(NewPipe.Length);

    cout << "Enter the pipe diameter: ";
    check_int(NewPipe.Diameter);

    cout << "Enter repair status: 0 (No) or 1 (Yes)?  ";
    check_bool(NewPipe.Repair);

    return NewPipe;

}

void PrintAddPipe(Pipe& NewPipe)

{
    cout << endl << "Info about the created pipe" << endl;
    if (NewPipe.NamePipe == "None")
    {
        cout << "The pipe has not been created yet!\n";
    }
    else
    {
        cout << "Name pipe: " << NewPipe.NamePipe
            << "\tLength pipe: " << NewPipe.Length
            << "\tDiameter pipe: " << NewPipe.Diameter
            << "\tRepair: " << NewPipe.Repair << endl;
    }
}




Station AddStation()

{
    Station NewStation;
    cout << endl << "Adding a new CS..." << endl;
    cout << "Enter the station name: ";
    cin >> NewStation.NameStation;

    cout << "Enter the number of workshops: ";
    check_int(NewStation.NumberWorkshops);

    cout << "Enter the number of active workshops: ";
    check_int(NewStation.ActiveWorkshops);

    while (NewStation.ActiveWorkshops > NewStation.NumberWorkshops)
    {
        cout << "The number of active workshops cannot be greater than those available!\n";
        cout << "Enter the number of active workshops: ";
        check_int(NewStation.ActiveWorkshops);
    }

    cout << "Enter the station efficiency indicator (from 0 to 1 with tenths): ";
    check2_float(NewStation.Effectivness);

    return NewStation;
}

void PrintAddStation(Station& NewStation)

{
    cout << endl << "Info about your CS..." << endl;
    if (NewStation.NameStation == "None")
    {
        cout << "No stations available!\n";
    }

    else
    {
        cout << "Name: " << NewStation.NameStation 
             << "\tWorkshops: " << NewStation.NumberWorkshops
             << "\tActive workshops: " << NewStation.ActiveWorkshops 
             << "\tEfficiency: " << NewStation.Effectivness << endl;

    }

}



int main()
{
    Pipe pipe0;
    Station station0;
    Pipe repair0;


    int menu;
    while (true) {
        cout << "\nMenu" << endl
            << "1. Add pipe" << endl
            << "2. Add CS" << endl
            << "3. Show all objects" << endl
            << "4. Edit status <Under repair>" << endl
            << "5. Edit Workshop start/stop" << endl
            << "6. Save changes" << endl
            << "7. Download to file" << endl
            << "8. Exit " << endl
            << endl << "Select command: ";
        cin >> menu;
        if (cin.fail() || menu < 1 || menu > 8)
        {
            cout << " Please, enter a command number from 1 to 8" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }


        switch (menu)
        {
        case 1: //add pipe 
        {
            pipe0 = AddPipe();
            PrintAddPipe(pipe0);
            break;
        }
        case 2:
        {
            station0 = AddStation();
            PrintAddStation(station0);
            break;
        }
        
        case 8:
        {
            return false;
            break;
        }
        }

    }
    return 0;
}