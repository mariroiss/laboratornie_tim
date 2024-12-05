
#include "pipe.h"
#include <iostream>
#include "utils.h"

#include<unordered_map>
 
using namespace std;

int Pipe::current_pipeid = 0;

int Pipe::Get_currentid() {
	return Pipe::current_pipeid;
}

int Pipe::GetId()
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

void Pipe::set_currentid(const unordered_map<int, Pipe>& data) {
	Pipe::current_pipeid = Get_maxid(data);
}

Pipe::Pipe()
{
	id = 0;
	name = "None";
	diameter = 0;
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
	file << repair << endl;
}

Pipe::Pipe(ifstream& file)
{
	file >> this->id;
	file.ignore(10000, '\n');
	getline(file >> ws, this->name);
	file >> this->length;
	file >> this->diameter;
	file >> this->repair;
}

void Pipe::AddPipe()
{
	cout << "Name pipe name: " << endl;
	INPUT_LINE(cin, this->name);
	cout << "Enter the pipe length: " << endl;
	length = GetCorrectNumber(1, 10000);
	cout << "Enter the pipe diameter : " << endl;
	diameter = GetCorrectNumber(1, 10000);
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
		cout << " Length: " << length << endl;
		cout << " Diameter: " << diameter << endl;
		cout << " Repair: " << repair << endl;
	}
}
