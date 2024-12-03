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

void Download(unordered_map<int, Pipe>& pipemap, unordered_map<int, CS>& csmap)
{
	cout << "Enter a file name" << endl;
	string filename;
	getline(cin >> ws, filename);
	ifstream file(filename);
	int countpipe = 0;
	int countcs = 0;
	if (file.is_open())
	{
		pipemap.clear();
		csmap.clear();
		string line;
		while (file >> line)
		{
			if (line == "Pipe") {
				load(file, pipemap);
				++countpipe;
			}
			else if (line == "Cs") {
				load(file, csmap);
				++countcs;
			}
		}
		file.close();
		cout << "The data has been downloaded" << endl;
	}
	else
	{
		cout << "Error opening file" << endl;
	}
	Pipe::maxid = countpipe;
	CS::maxid = countcs;
}