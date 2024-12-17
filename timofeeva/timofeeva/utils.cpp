#include "utils.h"
#include <unordered_set>

using namespace std;


int GetCorrectDiameter() {
    unordered_set<int> dia = { 500, 700, 1000, 1400 };
    int value;

    while (1) {
        value = GetCorrectNumber(500, 1400);
        if (dia.contains(value))
            return value;
        else
            cout << "input correct diameter (500, 700, 1000, 1400)" << endl;
    }
}
