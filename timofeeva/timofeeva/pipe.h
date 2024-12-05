#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

class Pipe
{
private:
    
    string name;
    double length;
    int diameter;
    bool repair;
    int id ;
    static int current_pipeid;


public:
    Pipe();
    int GetId();
    string GetName() const;
    static int Get_currentid();
    void Clear_currentid();
    static void set_currentid(const unordered_map<int, Pipe>& data);
    bool GetRepair() const;
    void AddPipe();
    void Show() const;
    void ChangeRepair();
    
    void pipe_save(ofstream& file) const;
    Pipe(ifstream& file);
};


