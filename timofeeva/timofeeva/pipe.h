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
    static int current_pipeid;


public:
    Pipe();
    int GetId();
    string GetNamePipe();
    static int Get_currentid();
    void Clear_currentid();
    static void set_currentid(const unordered_map<int, Pipe>& data);
    bool GetRepair();
    void AddPipe();
    void ShowPipe();
    string name;
    void ChangeRepair();
    
    void pipe_save(ofstream& file) const;
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


