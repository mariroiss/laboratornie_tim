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

    vector<int> links = {0, 0};

public:
    Pipe();
    int GetId() const;
    string GetName() const;
    static int Get_currentid();
    void Clear_currentid();
    static void set_currentid(const unordered_map<int, Pipe>& data);
    bool GetRepair() const;
    void AddPipe();
    void Show() const;
    void ChangeRepair();
    int get_diameter() const;

    bool IsUsing() const;
    vector<int> get_links() const;
    bool set_links(const int& out, const int& in);
    Pipe(const int& dia);
    
    void pipe_save(ofstream& file) const;
    Pipe(ifstream& file);
};


