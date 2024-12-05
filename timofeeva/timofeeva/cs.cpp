#include "cs.h"
#include "utils.h"
#include <string>
#include <unordered_map>


using namespace std;

int CS::current_csid = 0;

int CS::Get_currentid() {
    return CS::current_csid;
}

int CS::GetId()
{
    return this->id;
}

string CS::GetName() const
{
    return name;
}

int CS::GetNumberofWorkshops() const {
    return this->workshops;
}

int CS::GetNumberofActiveWorkshops() const {
    return this->act_workshops;
}

int CS::GetEffeciency() {
    return this->efficiency;
}

void CS::SetNumberofActiveWorkshops(int new_act_workshops) {
    act_workshops = new_act_workshops;
}

void CS::Clear_currentid() {
    CS::current_csid = 1;
}

void CS::set_currentid(const unordered_map<int, CS>& data) {
    CS::current_csid = Get_maxid(data);
}

CS::CS()
{
    id = 0;
    name = "None";
    workshops = 0;
    act_workshops = 0;
    efficiency = 0;
}


void CS::cs_save(ofstream& file)
{
    file << "Cs" << endl;
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
    act_workshops = GetCorrectNumber(0, workshops);
    cout << "Efficiency status (1...100)% : " << endl;
    efficiency = GetCorrectNumber(0, 100);
    id = ++current_csid;

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

