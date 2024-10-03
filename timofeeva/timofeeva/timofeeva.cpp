#include <iostream> 
#include <fstream> 
#include <string>
using namespace std;

struct Pipe {
    string NameP;
    float Length;
    int Diameter;
    bool Repair;
};

struct Cs
{
    string NameCS;
    int Workshops;
    int ActiveWorkshops;
    int Effectivness;
};

int pr_int(string message, int mn, int mx)
{
    int a;
    while ((cin>>a).fail() || cin.peek() != '\n' || a < mn || a > mx)
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << message;
    }
    return a;
}

float pr_float(string n, int mn, int mx)
{
    float a;
    while ((cin >> a).fail() || cin.peek() != '\n' || a < mn || a > mx)
    {
        cin.clear();
        cin.ignore(100000, '\n');

        cin >> a;
    }
    return a, mn, mx;
}


 Pipe sozd_pipe()
{
    Pipe N;
    cout << endl << "Creating a new pipe" << endl;
    cout << "Enter the name of the pipe: ";

    cin >> ws;
    getline(cin, N.NameP);

    cout << "Enter the length of the pipe: ";
    N.Length= pr_float("\nPlease, enter an int type (0, 10000)\n", 0, 10000);

    cout << "Enter the pipe diameter: ";
    N.Diameter= pr_int("\nPlease, enter an int type (0, 10000) \n", 0, 10000);

    cout << "Enter repair status: 0 (No) or 1 (Yes)?  ";
    N.Repair = pr_int("Enter an bool type(0 or 1)", -1, 2);

    return N;
}

void print_p(Pipe& N)
{
    cout << endl << "Info about the created pipe" << endl;
    if (N.NameP == "")
    {
        cout << "The pipe has not been created yet!\n";
    }
    else
    {
        cout << "Name pipe: " << N.NameP
            << "\tLength pipe: " << N.Length
            << "\tDiameter pipe: " << N.Diameter
            << "\tRepair: " << N.Repair << endl;
    }
}

void repair(Pipe& N)
{
    if (N.NameP == "")
    {
        cout << "No pipes available!\n";
    }
    else
    {
        N.Repair = !N.Repair;
        cout << endl << "You have changed repair status!";
        print_p(N);
    }
}

Cs sozd_cs()
{
    Cs s;
    cout << endl << "Adding a new CS..." << endl;
    cout << "Enter the station name: ";
    cin >> ws;
    getline(cin, s.NameCS);

    cout << "Enter the number of workshops: ";
    s.Workshops= pr_int("\nPlease, enter an int type > 0\n", 0, 10000);

    cout << "Enter the number of active workshops: ";
    s.ActiveWorkshops=pr_int("\nPlease, enter an int type > 0 and <Workshops \n", 0, s.Workshops);

    cout << "Enter the station efficiency indicator (from 0 to 5 with tenths): ";
    s.Effectivness = pr_int("\nPlease, enter a efficiency data from 0 to 5\n", 0, 6);

    return s;

}

void print_cs(Cs& s)
{
    cout << endl << "Info about the created CS" << endl;
    if (s.NameCS == "")
    {
        cout << "The CS has not been created yet!\n";
    }
    else
    {
        cout << "Name: " << s.NameCS
            << "\tWorkshops: " << s.Workshops
            << "\tActive workshops: " << s.ActiveWorkshops
            << "\tEfficiency: " << s.Effectivness << endl;
    }
}

void edit(Cs& s)
{
    if (s.NameCS == "")
    {
        cout << "No stations available!\n";
    }

    else
    {
        cout << "Enter the number of active workshops: ";
        s.ActiveWorkshops= pr_int("The number of active workshops cannot be greater than those available!\n", 0, s.ActiveWorkshops);

    }
    print_cs(s);
}

void in_file1(ofstream& fout, const Pipe& pipe) {
    if (pipe.NameP == "") {
        cout << "There is no data about the pipe to write to the file\n";
    }
    else {
        fout << "pipe" << endl;
        fout << pipe.NameP << endl;
        fout << pipe.Length << endl;
        fout << pipe.Diameter << endl;
        fout << pipe.Repair << endl;
        cout << "The data about the pipe is written\n";
    }
}

void in_file2(ofstream& fout,  const Cs& s) {
    if (s.NameCS == "") {
        cout << "There is no data about the station to write to the file\n";
    }
    else {
        fout << "station" << endl;
        fout << s.NameCS << endl;
        fout << s.Workshops << endl;
        fout << s.ActiveWorkshops << endl;
        fout << s.Effectivness << endl;
        cout << "The data about the station is written\n";
    }
}

void from_file_pipe(ifstream& fin, Pipe& p) {
    cout << "The data about the pipe was read from the file" << endl;
    cout << "Info about your pipe: " << endl;
    getline(fin >> ws, p.NameP);
    cout << "Name: " << p.NameP << endl;
    fin >> p.Length;
    cout << "Length:" << p.Length << endl;
    fin >> p.Diameter;
    cout << "Diameter:" << p.Diameter << endl;
    fin >> p.Repair;
    cout << "Repair:" << p.Repair << endl;
}

void from_file_station(ifstream& fin, Cs& s) {
    cout << "The data about the station was read from the file" << endl;
    cout << "Info about your station: " << endl;
    getline(fin >> ws, s.NameCS);
    cout << "Name: " << s.NameCS << endl;
    fin >> s.Workshops;
    cout << "Number of workshops: " << s.Workshops << endl;
    fin >> s.ActiveWorkshops;
    cout << "Number of working workshops: " << s.ActiveWorkshops << endl;
    fin >> s.Effectivness;
    cout << "Efficiency: " << s.Effectivness << endl;
}

void all_from_file(ifstream& fin, Pipe& p, Cs& s) {
    string line;
    while (getline(fin >> ws, line)) {
        if (line == "pipe") {
            from_file_pipe(fin, p);
        }
        else if (line == "station") {
            from_file_station(fin, s);
        }
    }
}

int main()
{
    Pipe p1;
    Cs st1;

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
            p1= sozd_pipe();
            print_p(p1);
            break;
        }
        case 2:
        {
            st1= sozd_cs();
            print_cs(st1);
            break;
        }
        case 3:
        {
            print_p(p1);
            print_cs(st1);
            break;
        }
        case 4:
        {
            repair(p1);
            break;
        }
        case 5:
        {
            edit(st1);
            break;
        }
        case 6:
        {
            ofstream fout;
            fout.open("vivod.txt", ios::out);
            if (fout.is_open()) {
                in_file1(fout, p1);
                in_file2(fout, st1);
                fout.close();
            }
            break;
        }
        case 7:
        {
            ifstream fin;
            fin.open("vivod.txt", ios::in);
            if (fin.is_open()) {
                all_from_file(fin, p1, st1);
                if (p1.NameP == "") {
                    cout << "There is no data about the pipe in the file\n";
                }
                if (st1.NameCS == "") {
                    cout << "There is no data about the station in the file\n";
                }
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