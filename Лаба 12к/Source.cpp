#include <iostream>
#include "MapFunctions.h"
#include "Money.h"
#include "Vector.h"

using namespace std;

int main() {
    setlocale(0, "");

    // Задача 1
    map<double, double> myMap = createAndFillMap();
    addToMap(myMap, 6.6, 60.5);
    removeFromMap(myMap, 3.3);
    performTask(myMap);

    // Задача 2
    Money money1, money2;
    cout << "Введите первую сумму:" << endl;
    cin >> money1;
    cout << "Введите вторую сумму:" << endl;
    cin >> money2;
    cout << "Результат сложения: " << money1 + money2 << endl;
    cout << "Результат вычитания: " << money1 - money2 << endl;

    // Задача 3
    Vector<double> doubleVector;
    doubleVector.addElementAtPosition(10.5, 0);
    doubleVector.addElementAtPosition(20.5, 1);
    doubleVector.addElementAtPosition(30.5, 2);
    doubleVector.displayElements();
    doubleVector.removeElementByKey(20.5);
    doubleVector.displayElements();
    doubleVector.subtractDifference();
    doubleVector.displayElements();

    return 0;
}
