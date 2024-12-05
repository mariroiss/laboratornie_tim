#include "pipe.h"
#include "cs.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

using namespace std;



void ShowAll(unordered_map<int, Pipe> pipemap, unordered_map<int, CS> cssmap)
{
	if (pipemap.empty())
	{
		cout << "Sorry, no pipes" << endl;
	}
	else
	{
		for (auto& pair : pipemap)
		{
			cout << "Pipes" << endl;
			pair.second.Show();
		}
	}
	if (cssmap.empty())
	{
		cout << "Sorry, no stations" << endl;
	}
	else
	{
		for (auto& pair : cssmap)
		{
			cout << "Stations" << endl;
			pair.second.Show();
		}
	}
}

void SaveAll(unordered_map<int, Pipe>& pipemap, unordered_map<int, CS>& cssmap)
{
	cout << "Enter a file name" << endl;
	string filename;
	getline(cin >> ws, filename);
	ofstream file(filename);
	if (file.is_open())
	{
		for (auto& pair : pipemap) {
			pair.second.pipe_save(file);
		}
		for (auto& pair : cssmap) {
			pair.second.cs_save(file);
		}
		file.close();
		cout << "The data has been saved" << endl;
	}
	else {
		cout << "Error" << endl;
	}
}


void Download(std::unordered_map<int, Pipe>& pipesmap, unordered_map<int, CS>& cs, std::unordered_set<int>& selected_pipe, std::unordered_set<int>& selected_cs) {
	string filename = "-1";

	cout << "Enter a file name" << endl;
	getline(cin >> ws, filename);
	ifstream file(filename);


	if (file.is_open()) {
		pipesmap.clear();
		selected_pipe.clear();

		cs.clear();
		selected_cs.clear();

		string line;

		while (file >> line) {
			if (line == "Pipe") {
				load(file, pipesmap);
			}

			if (line == "CS") {
				load(file, cs);
			}
		}

		file.close();
		Pipe::set_currentid(pipesmap);
		CS::set_currentid(cs);

	}
	else {
		cout << "Error opening file!" << endl;
	}

	cout << " objects was added!" << endl;
}

void change_selectedPipes_workStatus(unordered_map<int, Pipe>& pipes, const unordered_set<int>& selected_pipes) {
	for (const int& id : selected_pipes) {
		pipes.find(id)->second.ChangeRepair();
	}
	cout<< " Pipes were changed!" << endl;
}


void EditCS(unordered_map<int, CS>& cssmap, const unordered_set<int>& selected_cs) {
	int choice;

	if (cssmap.empty()) {
		cout << "No CSS" << std::endl;
		return;
	}
	cout << "input choice 0/1: ";
	choice = GetCorrectNumber(0, 1);
	
	for (const auto& id: selected_cs) {
		cssmap.at(id).edit_workshop_status(choice);
	}
}


