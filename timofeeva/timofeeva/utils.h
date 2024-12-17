#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;


#define INPUT_LINE(in, str) in.ignore(1000, '\n'); \
                            getline(in>>std::ws, str); \
                            std::cerr << str << std::endl;


template <typename T>
T GetCorrectNumber(T min, T max)
{
    T value;
    while ((cin >> value).fail()
        || cin.peek() != '\n'
        || value < min || value > max)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\nEnter a right number from " << min << " to " << max << "\n ";
    }
    cerr << value << endl;
    return value;
}



template<typename T>
int Get_maxid(const std::unordered_map<int, T>& objs) {
    int id = 0;
    for (auto& [k, v] : objs) {
        if (k > id) id = k;
    }
    return id;
}


int GetCorrectDiameter();
