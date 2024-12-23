#include "cs.h"
#include "utils.h"
#include <string>
#include <unordered_map>
#include <sstream>

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


bool CS::IsUsing() const {
    return (this->links[0].size()) || (this->links[1].size());
}


std::vector<std::unordered_set<int>> CS::get_links() const {
    return this->links;
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


bool CS::addLink(const int& pos, const int& id) {
    this->links[pos].emplace(id);
    return 1;
}


bool CS::deleteLink(const int& pos, const int& id) {
    if (this->links[pos].contains(id)) {
        this->links[pos].erase(id);
        return 1;
    }

    return 0;
}


void CS::set_links(std::ifstream& file, const int& pos) {
    string line;
    getline(file >> std::ws, line);
    istringstream iss(line);
    int id;
    while (iss >> id)
        if (id)
            this->addLink(pos, id);
    file.clear();
}



void CS::cs_save(ofstream& file)
{
    file << "CS"<< endl;
    file << id << endl;
    file << name << endl;
    file << workshops << endl;
    file << act_workshops << endl;
    file << efficiency << endl;

    if (this->links[0].size())
        for (const auto& id : this->links[0]) file << id << " ";
    else
        file << 0;
    file << endl;

    if (this->links[1].size())
        for (const auto& id : this->links[1]) file << id << " ";
    else
        file << 0;
    file << endl;
}

CS::CS(ifstream& file)
{
    file >> this->id;
    file.ignore(10000, '\n');
    getline(file >> ws, this->name);
    file >> this->workshops;
    file >> this->act_workshops;
    file >> this->efficiency;
    file.ignore(10000, '\n');
    this->set_links(file, 0);
    this->set_links(file, 1);
}

void CS::AddCS()
{
    cout << "Name cs: " << endl;
    INPUT_LINE(cin, this->name);
    cout << "Number of workshops: " << endl;
    workshops = GetCorrectNumber(1, 10000);
    cout << "Number of active workshops(must be < total workshops) " << endl;
    act_workshops = GetCorrectNumber(0, workshops);
    cout << "Efficiency status (1...100)% : " << endl;
    efficiency = GetCorrectNumber(0, 100);
    id = ++current_csid;

}

void CS::Show() const
{

    if (workshops == 0)
    {
        cout << "Sorry, you don't have any stations\n";
    }

    else
    {
        cout << "ID " << id << endl;
        cout << "Name cs: " << name << endl;
        cout << "Workshops: " << workshops << endl;
        cout << "Active workshops: " << act_workshops << endl;
        cout << "Efficiency: " << efficiency << "/100" << endl;
        cout << "links{" << endl;
        cout << "   " << "in: ";
        for (const auto& id : links[0]) 
            cout << id << " ";
        cout << endl;
        cout << "   " << "out: ";
        for (const auto& id : links[1]) 
            cout << id << " ";
        cout << endl;
        cout << "}" << endl;
        cout << endl;
    }
}

void CS::edit_workshop_status(int choice) {
    if (choice == 1) {
        if (this->act_workshops > 0) {
            --this->act_workshops;
        };
    }
    else {
        if (this->act_workshops < this->workshops) {
            ++this->act_workshops;
        };
    };

}