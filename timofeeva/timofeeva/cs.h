#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_map>
#include <fstream>

using namespace std;

class CS
{
private:
    string namecs;
    int workshops;
    int act_workshops;
    int efficiency;
    int id;

public:
    CS();
    int getid();
    void cs_save(ofstream& file);
    void cs_create();
    void cs_show();
    static int maxid;


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
