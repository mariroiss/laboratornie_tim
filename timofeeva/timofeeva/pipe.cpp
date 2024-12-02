
#include "pipe.h"
#include <iostream>
#include "utils.h"

using namespace std;

int PIPE::maxid = 1;

int PIPE::getid()
{
	return id;
}



void PIPE::pipe_create()
{
	cout << "Name pipe name: " << endl;
	getline(cin >> ws, namepipe);
	cout << "Enter the pipe length: " << endl;
	length = GetCorrectNumber(1, 10000);
	cout << "Enter the pipe diameter : " << endl;
	diameter = GetCorrectNumber(1, 10000);
	cout << "Enter the repair status(1/0): " << endl;
	repair = GetCorrectNumber(0, 1);
	id = maxid;
	maxid++;
}

void PIPE::pipe_show()
{
	if (diameter == 0)
	{
		cout << "You don't have any pipes!\n";
	}
	else
	{
		cout << "ID " << id << endl;
		cout << "Name: " << namepipe << endl;
		cout << " Length: " << length << endl;
		cout << " Diameter: " << diameter << endl;
		cout << " Repair: " << repair << endl;
	}
}
void pipe_menu(unordered_map<int, PIPE>& pipes)
{
	while (1) {
		cout << "1. Add pipe " << endl;
		cout << "2. Edit pipe " << endl;
		cout << "3. Delete pipe " << endl;
		cout << "0. Return to menu" << endl;
		int option = GetCorrectNumber(0, 8);
		switch (option)
		{
		case 1:
		{
			PIPE p;
			p.pipe_create();
			pipes.emplace(p.getid(), p);
			break;
		};
		case 2:
		{
			break;
		};
		case 3:
		{
			break;
		};
		case 0:
		{
			return;
		}
		}
	}
}
