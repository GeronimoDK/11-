#pragma once
#include <iostream>
#include <list>
using namespace std;

class Container {
private:
    list<double> elements;

public:
    void addElement(double element);
    void removeElement(double element);
    void printElements();
    void taskExecution();
};
