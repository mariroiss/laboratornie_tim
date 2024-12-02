#include "pipe.h"
#include "cs.h"
#include "utils.h"
#include <string>
#include <iostream>
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