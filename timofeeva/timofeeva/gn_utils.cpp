#include "utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include "GN.h"

using namespace std;



void GasNetwork::ShowAll()
{
	if (this->pipesmap.empty())
	{
		cout << "Sorry, no pipes" << endl;
	}
	else
	{
		for (auto& pair : this->pipesmap)
		{
			cout << "Pipes" << endl;
			pair.second.Show();
		}
	}
	if (this->cssmap.empty())
	{
		cout << "Sorry, no stations" << endl;
	}
	else
	{
		for (auto& pair : this->cssmap)
		{
			cout << "Stations" << endl;
			pair.second.Show();
		}
	}
}

void GasNetwork::SaveAll()
{
	cout << "Enter a file name" << endl;
	string filename;
	getline(cin >> ws, filename);
	ofstream file(filename);
	if (file.is_open())
	{
		for (auto& pair : this->pipesmap) {
			pair.second.pipe_save(file);
		}
		for (auto& pair : this->cssmap) {
			pair.second.cs_save(file);
		}
		file.close();
		cout << "The data has been saved" << endl;
	}
	else {
		cout << "Error" << endl;
	}
}


void GasNetwork::Download() {
	string filename = "-1";

	cout << "Enter a file name" << endl;
	getline(cin >> ws, filename);
	ifstream file(filename);


	if (file.is_open()) {
		this->pipesmap.clear();
		this->selected_pipes.clear();

		this->cssmap.clear();
		this->selected_cs.clear();

		string line;

		while (file >> line) {
			if (line == "Pipe") {
				load(file, this->pipesmap);
			}

			if (line == "CS") {
				load(file, this->cssmap);
			}
		}

		file.close();
		Pipe::set_currentid(this->pipesmap);
		CS::set_currentid(this->cssmap);

	}
	else {
		cout << "Error opening file!" << endl;
	}

	cout << " objects was added!" << endl;
}

void GasNetwork::change_selectedPipes_workStatus() {
	for (const int& id : this->selected_pipes) {
		this->pipesmap.find(id)->second.ChangeRepair();
	}
	cout<< " Pipes were changed!" << endl;
}


void GasNetwork::EditCS() {
	int choice;

	if (this->cssmap.empty()) {
		cout << "No CSS" << std::endl;
		return;
	}
	cout << "input choice 0/1: ";
	choice = GetCorrectNumber(0, 1);
	
	for (const auto& id: this->selected_cs) {
		this->cssmap.at(id).edit_workshop_status(choice);
	}
}


void GasNetwork::load(ifstream& file, unordered_map<int, Pipe>& map)
{
	Pipe object(file);
	map.emplace(object.GetId(), object);
}


void GasNetwork::load(ifstream& file, unordered_map<int, CS>& map)
{
	CS object(file);
	map.emplace(object.GetId(), object);
}



void GasNetwork::PrintSelectedPipes() {
	if (this->selected_pipes.empty()) {
		std::cout << "No selected items." << std::endl;
	}
	else {
		for (const int& id : this->selected_pipes) {
			auto it = this->pipesmap.find(id);
			if (it != this->pipesmap.end()) {
				it->second.Show();
			}
		}
	}
}


void GasNetwork::PrintSelectedCS() {
	if (this->selected_cs.empty()) {
		std::cout << "No selected items." << std::endl;
	}
	else {
		for (const int& id : this->selected_cs) {
			auto it = this->cssmap.find(id);
			if (it != this->cssmap.end()) {
				it->second.Show();
			}
		}
	}
}


void GasNetwork::clearSelectedPipes() {
	this->selected_pipes.clear();
	cout << "selected pipes are cleared" << endl;
}


void GasNetwork::clearSelectedCS() {
	this->selected_cs.clear();
	cout << "selected cs are cleared" << endl;
}

