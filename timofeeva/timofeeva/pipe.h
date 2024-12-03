#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
using namespace std;

class PIPE
{
private:
    string namepipe;
    double length;
    int diameter;
    bool repair;
    int id ;


public:
    PIPE();
    int getid();
    void pipe_save(ofstream& file);
    void pipe_create();
    void pipe_show();
    static int maxid;
    
};

template <typename T>
void showp(unordered_map<int, T>& map)
{
    for (auto& pair : map)
    {
        pair.second.showpipe();
    }
}
void pipe_menu(unordered_map<int, PIPE>& pipes);

