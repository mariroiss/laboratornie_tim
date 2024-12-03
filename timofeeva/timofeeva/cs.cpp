
#include "cs.h"
#include "utils.h"
#include <string>
#include <unordered_map>


using namespace std;

int CS::maxid = 0;

int CS::getid()
{
    return id;
}

CS::CS()
{
    id = ++maxid;
    namecs = "None";
    workshops = 0;
    act_workshops = 0;
    efficiency = 0;
}



void CS::cs_save(ofstream& file)
{
    file << "Station" << endl;
    file << id << endl;
    file << namecs << endl;
    file << workshops << endl;
    file << act_workshops << endl;
    file << efficiency << endl;
}

void CS::cs_create()
{
    cout << "Name cs: " << endl;
    getline(cin >> ws, namecs);
    cout << "Number of workshops: " << endl;
    workshops = GetCorrectNumber(1, 10000);
    cout << "Number of active workshops(must be < total workshops) " << endl;
    act_workshops = GetCorrectNumber(1, workshops);
    cout << "Efficiency status (1...100)% : " << endl;
    efficiency = GetCorrectNumber(0, 100);
    id = maxid;
    maxid++;

}

void CS::cs_show()
{

    if (workshops == 0)
    {
        cout << "Sorry, you don't have any stations\n";
    }

    else
    {
        cout << "ID " << id << endl;
        cout << "Name cs: " << namecs << endl;
        cout << " Workshops: " << workshops << endl;
        cout << " Active workshops: " << act_workshops << endl;
        cout << " Efficiency: " << efficiency << "/100" << endl;
    }
}

void cs_menu(unordered_map<int, CS>& stations)
{
    while (1) {
        cout << "1. Add station " << endl;
        cout << "0. Exit" << endl;

        int name = GetCorrectNumber(0, 2);
        switch (name)
        {

        case 1:
        {
            CS p;
            p.cs_create(); //создала для объекта р кс
            stations.emplace(p.getid(), p); //добавила элемент в контейнер
            break;
        };
        case 2:
        {
            break;
        };

        case 0:
        {
            return;
        }
        }
    }
}




/* ifstream& operator >> (ifstream& fin, css& s)
{
    fin >> s.id;
    fin >> ws;
    getline(fin, s.namecs);
    fin >> s.workshops;
    fin >> s.act_workshops;
    fin >> s.efficiency;
    s.maxid = s.id;

    return fin;
}

ofstream& operator << (ofstream& fout, const cs& s)
{
    if (s.namecs != "None");
    {
        fout << s.id << endl
            << s.namecs << endl
            << s.workshops << endl
            << s.act_workshops << endl
            << s.efficiency << endl;
    }
    return fout;
}

istream& operator>>(istream& in, cs& a)
{
    cout << "\n";
    cout << "Enter the name of the station:";
    INPUT_LINE(in, a.namecs);
    a.id = ++a.maxid;

    cout << "Enter the number of workshops:";
    a.workshops = GetCorrectNumber(1, 10000);

    cout << "Enter the number of working workshops: ";
    a.act_workshops = GetCorrectNumber(0, a.workshops);

    cout << "Enter the station efficiency as a %: ";
    a.efficiency = GetCorrectNumber(1, 100);

    cout << std::endl;
    return in;
}

ostream& operator<<(ostream& out, const cs& a)
{
    if (a.namecs == "") {
        std::cout << "No station available" << "\n";
    }
    else {
        if (a.namecs != "") {
            out << "\n";
            out << "id: " << a.id << endl;
            out << "Name: " << a.namecs << endl;
            out << "Number of workshops: " << a.workshops << endl;
            out << "Number of act workshops: " << a.act_workshops << endl;
            out << "Efficiency: " << a.efficiency << endl << endl;
        }
    }
    return out;
} */

