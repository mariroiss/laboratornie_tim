#include <iostream>
#include "GN.h"
#include "gn_utils.h"

using namespace std;


void GasNetwork::addPipe() {
    Pipe p;
    p.AddPipe();
    this->pipesmap.emplace(p.GetId(), p);
}


void GasNetwork::addCS() {
    CS cs;
    cs.AddCS();
    this->cssmap.emplace(cs.GetId(), cs);
}


void GasNetwork::delete_selectedPipes() {
    int counter = 0;
    for (auto it = this->selected_pipes.begin(); it != this->selected_pipes.end();) {
        this->erase_obj(this->pipesmap, *it);
        it = this->selected_pipes.erase(it);
        ++counter;
    }
    cout << counter << "pipes was erased!" << endl;
}


void GasNetwork::delete_selectedCS() {
    int counter = 0;
    for (auto it = this->selected_cs.begin(); it != this->selected_cs.end();) {
        this->erase_obj(this->cssmap, *it);
        it = this->selected_cs.erase(it);
        ++counter;
    }
    cout << counter << "cs was erased!" << endl;
}
