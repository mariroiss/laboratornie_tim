#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

class Pipe
{
private:
    
    string namepipe;
    double length;
    int diameter;
    bool repair;
    int id ;



public:
    Pipe();
    int GetId();
    string GetNamePipe();
    static int maxid;
    bool GetRepair();
    void AddPipe();
    void ShowPipe();
    string name;
    void ChangeRepair();
    
    void pipe_save(ofstream& file);
    Pipe(ifstream& file);
};

template <typename T>
void showp(unordered_map<int, T>& map)
{
    for (auto& pair : map)
    {
        pair.second.ShowPipe();
    }
}


