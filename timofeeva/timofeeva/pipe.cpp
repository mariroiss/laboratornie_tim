
#include "pipe.h"
#include <iostream>
#include "utils.h"

#include<unordered_map>
 
using namespace std;

int Pipe::maxid = 0;

int Pipe::GetId()
{
	return id;
}

string Pipe::GetNamePipe()
{
	return name;
}
bool Pipe::GetRepair()
{
	return repair;
}
void Pipe::ChangeRepair() {
	this->repair = !this->repair;
}

Pipe::Pipe()
{
	id = ++maxid;
	name = "None";
	diameter = 0;
	length = 0;
	repair = false;
}

void Pipe::pipe_save(ofstream& file)
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
	getline(cin >> ws, name);
	cout << "Enter the pipe length: " << endl;
	length = GetCorrectNumber(1, 10000);
	cout << "Enter the pipe diameter : " << endl;
	diameter = GetCorrectNumber(1, 10000);
	cout << "Enter the repair status(1/0): " << endl;
	repair = GetCorrectNumber(0, 1);
	id = maxid;
}

void Pipe::ShowPipe()
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
