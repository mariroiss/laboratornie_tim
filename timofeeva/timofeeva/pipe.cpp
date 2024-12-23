#include "pipe.h"
#include <iostream>
#include "utils.h"
#include<unordered_map>
 
using namespace std;

int Pipe::current_pipeid = 0;

int Pipe::Get_currentid() {
	return Pipe::current_pipeid;
}

int Pipe::GetId() const
{
	return this->id;
}

string Pipe::GetName() const
{
	return name;
}
bool Pipe::GetRepair() const
{
	return this->repair;
}
void Pipe::ChangeRepair() {
	this->repair = !this->repair;
}

void Pipe::Clear_currentid() {
	Pipe::current_pipeid = 1;
}


bool Pipe::IsUsing() const {
	return (this->links[0]) || (this->links[1]);
}


vector<int> Pipe::get_links() const {
	return this->links;
}


int Pipe::get_diameter() const {
	return this->diameter;
}


int Pipe::get_length() const {
	return this->length;
}


bool Pipe::set_links(const int& out, const int& in) {
	this->links = { out, in };
	return 1;
}


void Pipe::set_productivity() {
	unordered_map<int, int> productivities = {
		{500, 5},
		{700, 12},
		{1000, 30},
		{1400, 95}
	};

	this->productivity = productivities[this->diameter];
}


int Pipe::get_productivity() const {
	return this->productivity * this->repair;
}


Pipe::Pipe(const int& dia)
{
	cout << "Name pipe name: " << endl;
	INPUT_LINE(cin, this->name);
	cout << "Enter the pipe length: " << endl;
	length = GetCorrectNumber(1, 10000);
	cout << "diameter : ";
	diameter = dia;
	this->set_productivity();
	cout << "productivity : " << productivity << endl;
	cout << dia << endl;
	cout << "Enter the repair status(1/0): " << endl;
	repair = GetCorrectNumber(0, 1);
	id = ++current_pipeid;
}


void Pipe::set_currentid(const unordered_map<int, Pipe>& data) {
	Pipe::current_pipeid = Get_maxid(data);
}

Pipe::Pipe()
{
	id = 0;
	name = "None";
	diameter = 0;
	productivity = 0;
	length = 0;
	repair = false;
}

void Pipe::pipe_save(ofstream& file) const
{
	file << "Pipe" << endl;
	file << id << endl;
	file << name << endl;
	file << length << endl;
	file << diameter << endl;
	file << productivity << endl;
	file << repair << endl;
	file << links[0] << endl;
	file << links[1] << endl;
}

Pipe::Pipe(ifstream& file)
{
	file >> this->id;
	file.ignore(10000, '\n');
	getline(file >> ws, this->name);
	file >> this->length;
	file >> this->diameter;
	file >> this->productivity;
	file >> this->repair;
	file >> this->links[0];
	file >> this->links[1];
}

void Pipe::AddPipe()
{
	cout << "Name pipe name: " << endl;
	INPUT_LINE(cin, this->name);
	cout << "Enter the pipe length: " << endl;
	length = GetCorrectNumber(1, 10000);
	cout << "Enter the pipe diameter : " << endl;
	diameter = GetCorrectDiameter();
	this->set_productivity();
	cout << "productivity : " << productivity << endl;
	cout << "Enter the repair status(1/0): " << endl;
	repair = GetCorrectNumber(0, 1);
	id = ++current_pipeid;
}

void Pipe::Show() const
{
	if (diameter == 0)
	{
		cout << "You don't have any pipes!\n";
	}
	else
	{
		cout << "ID " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Length: " << length << endl;
		cout << "Diameter: " << diameter << endl;
		cout << "productivity : " << productivity << endl;
		cout << "Repair: " << repair << endl;
		cout << "links{" << endl
			<< "   " << "out: "
			<< links[0] << " " << endl
			<< "   " << "in: "
			<< links[1] << " "
			<< endl << "}" << endl
			<< endl;
	}
}
