#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
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
    static int current_csid;

    std::vector<std::unordered_set<int>> links = { {}, {} };

public:
    CS();
    int GetId();
    void AddCS();
    string GetName() const;
    static int Get_currentid();
    void Clear_currentid();
    static void set_currentid(const unordered_map<int, CS>& data);
    int GetNumberofWorkshops() const;
    int GetNumberofActiveWorkshops() const;
    int GetEffeciency();
    void SetNumberofActiveWorkshops(int new_act_workshops);
    void Show() const;
    CS(ifstream& file);
    void cs_save(ofstream& file);
    void edit_workshop_status(int choice);

    std::vector<std::unordered_set<int>> get_links() const;
    bool IsUsing() const;
    bool addLink(const int& pos, const int& id);
    bool deleteLink(const int& pos, const int& id);

    void set_links(std::ifstream& file, const int& pos);
};

