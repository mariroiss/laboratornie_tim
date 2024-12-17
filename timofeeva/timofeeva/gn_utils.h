#pragma once
#include "GN.h"


template<typename T>
void GasNetwork::erase_obj(std::unordered_map<int, T>& objs, const int id) {
    if (objs.count(id)) {
        objs.erase(id);
    }
    else {
        std::cout << "There is not object with id " << id << std::endl;
    }
}
