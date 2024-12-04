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
    string name;
    
    int workshops;
    int act_workshops;
    int efficiency;
    int id;

public:
    CS();
    int GetId();
    void AddCS();
    string GetNameCS();
    int GetNumberofWorkshops();
    int GetNumberofActiveWorkshops();
    int GetEffeciency();
    static int maxid;
    void SetNumberofActiveWorkshops(int new_act_workshops);
    void cs_show();
    CS(ifstream& file);
    void cs_save(ofstream& file);


};


template <typename T>
void showc(unordered_map<int, T>& map)
{
    for (auto& pair : map)
    {
        pair.second.cs_show();
    }
}

