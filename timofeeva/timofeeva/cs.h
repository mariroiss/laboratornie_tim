#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <istream>

using namespace std;

class CS
{
private:
    string namecs;
    int workshops;
    int act_workshops;
    int efficiency;
    static int maxid;
    int id;

public:

    int getid();
    void cs_create();
    void cs_show();

};


template <typename T>
void showc(unordered_map<int, T>& map)
{
    for (auto& pair : map)
    {
        pair.second.showcs();
    }
};

void cs_menu(unordered_map<int, CS>& stations);
