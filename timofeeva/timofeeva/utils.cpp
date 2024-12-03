#include "pipe.h"
#include "cs.h"
#include "utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>

void showall(unordered_map<int, PIPE> pipemap, unordered_map<int, CS> csmap)
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
			pair.second.pipe_show();
		}
	}
	if (csmap.empty())
	{
		cout << "Sorry, no stations" << endl;
	}
	else
	{
		for (auto& pair : csmap)
		{
			cout << "Stations" << endl;
			pair.second.cs_show();
		}
	}
}

void save(unordered_map<int, PIPE>& pipes, unordered_map<int, CS>& stations)
{
	cout << "Enter a file name" << endl;
	string filename;
	getline(cin >> ws, filename);
	ofstream file(filename);
	if (file.is_open())
	{
		for (auto& pair : pipes) {
			pair.second.pipe_save(file);
		}
		for (auto& pair : stations) {
			pair.second.cs_save(file);
		}
		file.close();
		cout << "The data has been saved" << endl;
	}
	else {
		cout << "Error" << endl;
	}
}