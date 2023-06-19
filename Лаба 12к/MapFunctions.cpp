// MapFunctions.cpp
#include "MapFunctions.h"
#include <iostream>

map<double, double> createAndFillMap() {
    map<double, double> myMap;

    myMap[1.1] = 10.5;
    myMap[2.2] = 20.5;
    myMap[3.3] = 30.5;
    myMap[4.4] = 40.5;
    myMap[5.5] = 50.5;

    return myMap;
}

void addToMap(map<double, double>& myMap, double key, double value) {
    myMap[key] = value;
}

void removeFromMap(map<double, double>& myMap, double key) {
    myMap.erase(key);
}

void performTask(map<double, double>& myMap) {
    double maxElement = myMap.rbegin()->second;
    double minElement = myMap.begin()->second;

    for (auto& entry : myMap) {
        entry.second -= (maxElement - minElement);
    }

    cout << "Результат выполнения задания:" << endl;
    for (const auto& entry : myMap) {
        cout << entry.first << ": " << entry.second << endl;
    }
}
