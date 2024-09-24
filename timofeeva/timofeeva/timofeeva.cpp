#include <iostream> 
#include <fstream> 
using namespace std;

struct Pipe {
    string NamePipe = "None";
    float Length = 0.0;
    int Diameter = 0;
    bool Repair = false;
};

struct Station
{
    string NameStation = "None";
    int NumberWorkshops = 0;
    int ActiveWorkshops = 0;
    float Effectivness = 0;
};

int check_int(int& int_data)

{
    cin >> int_data;
    while (cin.fail() || cin.peek() != '\n' || int_data <= 0)

    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter an int type > 0\n";
        cin >> int_data;
    }
    return int_data;
}
float check_float(float& float_data)
{
    cin >> float_data;
    while (cin.fail() || cin.peek() != '\n' || float_data <= 0)

    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter a float type > 0\n";
        cin >> float_data;

    }
    return float_data;

}


float check2_float(float& Effectivness)

{
    cin >> Effectivness;
    while (cin.fail() || cin.peek() != '\n' || (Effectivness < 0) || (Effectivness > 5))
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter a efficiency data from 0 to 5\n";
        cin >> Effectivness;

    }

    return Effectivness;
}

bool check_bool(bool& bool_data)

{
    cin >> bool_data;
    while (cin.fail() || cin.peek() != '\n')
    {
        cin.clear();
        cin.ignore(100000, '\n');
        cout << "\nPlease, enter a bool type\n";
        cin >> bool_data;

    }
    return bool_data;
}

