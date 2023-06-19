#include <iostream>
#include <list>
#include <queue>
#include <map>
#include "money.h"
#include "container_operations.h"
#include "container_adapter_operations.h"
#include "associative_container_operations.h"

int main() {
    // Задача 1
    cout << "Task 1\n";
    cout << "------\n";
    list<Money> container1 = { Money(10, 99), Money(5, 50), Money(7, 75), Money(3, 30) };
    cout << "Container before operations: ";
    for (const Money& money : container1) {
        cout << money << " ";
    }
    cout << "\n";

    // Задание 3
    Money oldValue(5, 50);
    Money newValue(8, 80);
    replaceElements(container1, oldValue, newValue);
    cout << "Container after replacing " << oldValue << " with " << newValue << ": ";
    for (const Money& money : container1) {
        cout << money << " ";
    }
    cout << "\n";

    // Задание 4
    sortAscending(container1);
    cout << "Container after sorting in ascending order: ";
    for (const Money& money : container1) {
        cout << money << " ";
    }
    cout << "\n";

    // Задание 5
    Money valueToRemove(7, 75);
    removeElements(container1, valueToRemove);
    cout << "Container after removing " << valueToRemove << ": ";
    for (const Money& money : container1) {
        cout << money << " ";
    }
    cout << "\n";

    cout << "\n";

    // Задача 2
    cout << "Task 2\n";
    cout << "------\n";
    priority_queue<Money> container2;
    container2.push(Money(20, 50));
    container2.push(Money(10, 99));
    container2.push(Money(15, 75));
    cout << "Container before operations: ";
    while (!container2.empty()) {
        cout << container2.top() << " ";
        container2.pop();
    }
    cout << "\n";

    // Задание 3
    replaceElements(container2, oldValue, newValue);
    cout << "Container after replacing " << oldValue << " with " << newValue << ": ";
    container2 = priority_queue<Money>();  // Restore container2
    container2.push(Money(20, 50));
    container2.push(Money(10, 99));
    container2.push(Money(15, 75));
    while (!container2.empty()) {
        cout << container2.top() << " ";
        container2.pop();
    }
    cout << "\n";

    // Задание 4
    sortAscending(container2);
    cout << "Container after sorting in ascending order: ";
    container2 = priority_queue<Money>();  // Restore container2
    container2.push(Money(20, 50));
    container2.push(Money(10, 99));
    container2.push(Money(15, 75));
    while (!container2.empty()) {
        cout << container2.top() << " ";
        container2.pop();
    }
    cout << "\n";

    // Задание 5
    removeElements(container2, valueToRemove);
    cout << "Container after removing " << valueToRemove << ": ";
    container2 = std::priority_queue<Money>();  // Restore container2
    container2.push(Money(20, 50));
    container2.push(Money(10, 99));
    container2.push(Money(15, 75));
    while (!container2.empty()) {
        cout << container2.top() << " ";
        container2.pop();
    }
    cout << "\n";

    cout << "\n";

    // Задача 3
    cout << "Task 3\n";
    cout << "------\n";
    map<int, Money> container3 = {
        {1, Money(5, 50)},
        {2, Money(10, 99)},
        {3, Money(7, 75)},
        {4, Money(3, 30)}
    };
    cout << "Container before operations: ";
    for (const auto& pair : container3) {
        cout << pair.second << " ";
    }
    cout << "\n";

    // Задание 3
    replaceElements(container3, oldValue, newValue);
    cout << "Container after replacing " << oldValue << " with " << newValue << ": ";
    for (const auto& pair : container3) {
        cout << pair.second << " ";
    }
    cout << "\n";

    // Задание 4
    sortAscending(container3);
    cout << "Container after sorting in ascending order: ";
    for (const auto& pair : container3) {
        cout << pair.second << " ";
    }
    cout << "\n";

    // Задание 5
    removeElements(container3, valueToRemove);
    cout << "Container after removing " << valueToRemove << ": ";
    for (const auto& pair : container3) {
        cout << pair.second << " ";
    }
    cout << "\n";

    return 0;
}
