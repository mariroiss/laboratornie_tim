#include "cs.h"
#include "utils.h"
#include <string>
#include <unordered_map>;


using namespace std;

int CS::maxid = 0;

int CS::GetId()
{
    return id;
}

string CS::GetNameCS()
{
    return name;
}

int CS::GetNumberofWorkshops() {
    return workshops;
}

int CS::GetNumberofActiveWorkshops() {
    return act_workshops;
}

int CS::GetEffeciency() {
    return efficiency;
}

void CS::SetNumberofActiveWorkshops(int new_act_workshops) {
    act_workshops = new_act_workshops;
}

CS::CS()
{
    id = ++maxid;
    name = "";
    workshops = 0;
    act_workshops = 0;
    efficiency = 0;
}


void CS::cs_save(ofstream& file)
{
    file << "Station" << endl;
    file << id << endl;
    file << name << endl;
    file << workshops << endl;
    file << act_workshops << endl;
    file << efficiency << endl;
}

CS::CS(ifstream& file)
{
    file >> this->id;
    file.ignore(10000, '\n');
    getline(file >> ws, this->name);
    file >> this->workshops;
    file >> this->act_workshops;
    file >> this->efficiency;
}

void CS::AddCS()
{
    cout << "Name cs: " << endl;
    getline(cin >> ws, name);
    cout << "Number of workshops: " << endl;
    workshops = GetCorrectNumber(1, 10000);
    cout << "Number of active workshops(must be < total workshops) " << endl;
    act_workshops = GetCorrectNumber(1, workshops);
    cout << "Efficiency status (1...100)% : " << endl;
    efficiency = GetCorrectNumber(0, 100);
    id = maxid;

}

void EditCSbyId(unordered_map<int, CS>& cssmap) {
    int cs_id;
    int new_act;
    if (cssmap.empty()) {
        cout << "No CSS" << endl;
    }
    else {
        cout << "Enter id of cs to edit " << endl;
        cs_id = GetCorrectNumber(0, numeric_limits<int>::max());

        if (cssmap.count(cs_id) == 1) {
            while (1) {
                cout << "Enter new number of active workshops (0 to exit): ";
                new_act = GetCorrectNumber(0, numeric_limits<int>::max());
                if (new_act == 0) {
                    break;
                }
                if (new_act >= 0 && new_act <= cssmap[cs_id].GetNumberofWorkshops()) {
                    cssmap[cs_id].SetNumberofActiveWorkshops(new_act);
                    cout << "Number of active workshops updated to: " << new_act << endl;
                }
                else {
                    cout << "Active workshops must be between 0 and " << cssmap[cs_id].GetNumberofWorkshops() << endl;
                }
            }
        }
        else {
            cout << "No CS with this ID." << endl;
        }
    }
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
        cout << "Name cs: " << name << endl;
        cout << " Workshops: " << workshops << endl;
        cout << " Active workshops: " << act_workshops << endl;
        cout << " Efficiency: " << efficiency << "/100" << endl;
    }
}
/*
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
            stations.emplace(p.GetId(), p); //добавила элемент в контейнер
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

*/


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

