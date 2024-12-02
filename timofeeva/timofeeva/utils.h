#pragma once
#include <iostream>
#include "pipe.h"
#include "cs.h"



using namespace std;

template <typename T>
T GetCorrectNumber(T min, T max)
{
    T value;
    while ((cin >> value).fail()
        || cin.peek() != '\n'
        || value < min || value > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Type number from " << min << " to " << max << ": ";
    }
    cerr << value << endl;
    return value;
}



void showall(unordered_map<int, PIPE> pipemap, unordered_map<int, CS> csmap);
