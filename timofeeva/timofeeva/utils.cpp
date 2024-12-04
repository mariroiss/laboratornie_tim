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
			pair.second.ShowPipe();
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
			pair.second.cs_show();
		}
	}
}

/*void SaveAll(unordered_map<int, Pipe>& pipesmap, unordered_map<int, CS>& cssmap) {
	cout << "Enter a file name" << endl;
	string filename;
	getline(cin >> ws, filename);
	ofstream file(filename);

	if (file.is_open()) {

		if (pipesmap.empty()) {
			cout << "No pipes" << endl;
		}
		else {
			for (auto& pair : pipesmap) {
				pair.second.pipe_save(file); //?
			}
		}

		if (cssmap.empty()) {
			cout << "No compressor stations" << endl;
		}
		else {
			for (auto& cs : cssmap) {
				cs.second.cs_save(file);
			}
		}

		file.close();

		cout << " Objects was saved!" << endl;
	}
	else {
		cout << "Error opening file!" << endl;
	}

}*/


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
/*
void Download(unordered_map<int, Pipe>& pipemap, unordered_map<int, CS>& cssmap, unordered_set<int>& selected_pipe, unordered_set<int>& selected_cs)
{
	cout << "Enter a file name" << endl;
	string filename;
	getline(cin >> ws, filename);
	ifstream file(filename);
	if (file.is_open()) {
		pipemap.clear();
		selected_pipe.clear();
		cssmap.clear();
		selected_cs.clear();

		string line;

		while (getline(file, line)) {
			if (line.find("Pipe") == 0) {
				Pipe new_pipe;
				file >> new_pipe;
				cout << new_pipe;
				pipemap.emplace(new_pipe.GetId(), new_pipe);
				cout << "Pipe added!" << endl;
			}
			else if (line.find("CS") == 0) {
				CS new_cs;
				file >> new_cs;
				cout << new_cs;
				cssmap.emplace(new_cs.GetId(), new_cs);
				cout << "Cs added!" << endl;
			}
		}

		file.close();
	}
	else {
		cout << "Error opening file! The file '" << filename << "' could not be opened." << endl;
	}


}*/