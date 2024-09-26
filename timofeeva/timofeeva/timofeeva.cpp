#include <iostream> 
#include <fstream> 
#include <string>
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

int proverka_int(int& int_data)

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
float proverka_float(float& float_data)
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
//проверка на пробелы название

float proverka_float1(float& Effectivness)

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

bool proverka_bool(bool& bool_data)

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
    Pipe N;
    cout << endl << "Creating a new pipe" << endl;
    cout << "Enter the name of the pipe: ";

    cin >> ws;
    getline(cin, N.NamePipe);

    cout << "Enter the length of the pipe: ";
    proverka_float(N.Length);

    cout << "Enter the pipe diameter: ";
    proverka_int(N.Diameter);

    cout << "Enter repair status: 0 (No) or 1 (Yes)?  ";
    proverka_bool(N.Repair);

    return N;
}

void PrintAddPipe(Pipe& N)

{
    cout << endl << "Info about the created pipe" << endl;
    if (N.NamePipe == "None")
    {
        cout << "The pipe has not been created yet!\n";
    }
    else
    {
        cout << "Name pipe: " << N.NamePipe
            << "\tLength pipe: " << N.Length
            << "\tDiameter pipe: " << N.Diameter
            << "\tRepair: " << N.Repair << endl;
    }
}



void RepairPipe(Pipe& N)

{
    if (N.NamePipe == "None")
    {
        cout << "No pipes available!\n";
    }

    else

    {
        N.Repair = !N.Repair;
        cout << endl << "You have changed repair status!";
        PrintAddPipe(N);

    }

}


Station AddStation()

{
    Station NewStation;
    cout << endl << "Adding a new CS..." << endl;

    cout << "Enter the station name: ";
    cin >> ws;
    getline(cin, NewStation.NameStation);


    cout << "Enter the number of workshops: ";
    proverka_int(NewStation.NumberWorkshops);

    cout << "Enter the number of active workshops: ";
    proverka_int(NewStation.ActiveWorkshops);

    while (NewStation.ActiveWorkshops > NewStation.NumberWorkshops)
    {
        cout << "The number of active workshops cannot be greater than those available!\n";
        cout << "Enter the number of active workshops: ";
        proverka_int(NewStation.ActiveWorkshops);
    }

    cout << "Enter the station efficiency indicator (from 0 to 5 with tenths): ";
    proverka_float1(NewStation.Effectivness);

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

void EditStation(Station& NewStation)

{
    if (NewStation.NameStation == "None")
    {
        cout << "No stations available!\n";
    }

    else
    {
        cout << "Enter the number of active workshops: ";
        proverka_int(NewStation.ActiveWorkshops);

        while (NewStation.ActiveWorkshops > NewStation.NumberWorkshops)
        {
            cout << "The number of active workshops cannot be greater than those available!\n";
            cout << "Enter the number of active workshops: ";
            proverka_int(NewStation.NumberWorkshops);
        }
    }

    PrintAddStation(NewStation);

}

void in_file1(ofstream& fout, const Pipe& pipe) {
    if (pipe.NamePipe == "None") {
        cout << "There is no data about the pipe to write to the file\n";
    }
    else {
        fout << pipe.NamePipe << endl;
        fout << pipe.Length << endl;
        fout << pipe.Diameter << endl;
        fout << pipe.Repair << endl;
        cout << "The data about the pipe is written\n";
    }
}

void in_file2(ofstream& fout,  const Station& station) {
    if (station.NameStation == "None") {
        cout << "There is no data about the station to write to the file\n";
    }
    else {
        fout << station.NameStation << endl;
        fout << station.NumberWorkshops << endl;
        fout << station.ActiveWorkshops << endl;
        fout << station.Effectivness << endl;
        cout << "The data about the station is written\n";
    }
}

/* void from_file_pipe(ifstream& fin, Pipe& pipe) {
    string line;
    while (getline(fin, line)) {
        if (line.find("pipe", 0) == 0) {
            cout << "The data about the pipe was read from the file" << endl;
            cout << "Info about your pipe: " << endl;
            getline(fin, pipe.NamePipe);
            cout << "Name: " << pipe.NamePipe << endl;
            fin >> pipe.Length;
            cout << "Length:" << pipe.Length << endl;
            fin >> pipe.Diameter;
            cout << "Diameter:" << pipe.Diameter << endl;
            fin >> pipe.Repair;
            cout << "Repair:" << pipe.Repair << endl;
        }
        else {
            cout << "There is no data about the pipe in the file" << endl;
        }
        /*if (line.find("station", 0) == 0) {
            cout << "The data about the station was read from the file" << endl;
            cout << "Info about your station: " << endl;
            getline(fin, station.namecs);
            cout << "Name: " << station.namecs << endl;
            fin >> station.workshops;
            cout << "Number of workshops: " << station.workshops << endl;
            fin >> station.act_workshops;
            cout << "Number of workshops: " << station.act_workshops << endl;
            fin >> station.efficiency;
            cout << "Efficiency: " << station.efficiency << endl;
        }
        else {
            cout << "There is no data about the station in the file" << endl;
        }
        break;
    }
}
*/
void from_file_station(ifstream& fin, Station& station) {
    string line;
    int k = 0;
    while (getline(fin, line)) {
        k++;
        if (k == 6) {
            if (line.find("station", 0) == 0) {
                cout << "The data about the station was read from the file" << endl;
                cout << "Info about your station: " << endl;
                getline(fin, station.NameStation);
                cout << "Name: " << station.NameStation << endl;
                fin >> station.NumberWorkshops;
                cout << "Number of workshops: " << station.NumberWorkshops << endl;
                fin >> station.ActiveWorkshops;
                cout << "Number of working workshops: " << station.ActiveWorkshops << endl;
                fin >> station.Effectivness;
                cout << "Efficiency: " << station.Effectivness << endl;
            }
            else {
                cout << "There is no data about the station in the file" << endl;
            }
            break;
        }
    }
}



int main()
{
    Pipe pipe0;
    Station station0;

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
            pipe0= AddPipe();
            PrintAddPipe(pipe0);
            break;
        }
        case 2:
        {
            station0=AddStation();
            PrintAddStation(station0);
            break;
        }
        case 3:
        {
            PrintAddPipe(pipe0);
            PrintAddStation(station0);
            break;
        }
        case 4:
        {
            RepairPipe(pipe0);
            break;
        }
        case 5:
        {
            EditStation(station0);
            break;
        }
        case 6:
        {
            ofstream fout;
            fout.open("vivod.txt", ios::out);
            if (fout.is_open()) {
                in_file1(fout, pipe0);
                in_file2(fout, station0);
                fout.close();
            }
            break;
        }
        case 7:
        {
            ifstream fin;
            fin.open("vivod.txt", ios::in);
            if (fin.is_open()) {
                from_file_pipe(fin, pipe0);
                from_file_station(fin, station0);
                fin.close();
            }
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