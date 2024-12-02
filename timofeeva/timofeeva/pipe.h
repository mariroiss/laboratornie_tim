#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class PIPE
{
private:
    string namepipe = "None";
    double length = 0;
    int diameter = 0;
    bool repair = 0;
    int id = 0;
    static int maxid;

public:

    int getid();
    void pipe_create();
    void pipe_show();

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

