#ifndef CONTAINER_OPERATIONS_H
#define CONTAINER_OPERATIONS_H

#include <algorithm>
#include <list>
#include "money.h"

// �������� �������� � ������������ � ��������
void replaceElements(list<Money>& container, const Money& oldValue, const Money& newValue) {
    replace(container.begin(), container.end(), oldValue, newValue);
}

// ������� �������� � ������������ � ��������
void removeElements(list<Money>& container, const Money& value) {
    container.remove(value);
}

// ������������� ��������� �� ����������� ��������� ����
void sortAscending(list<Money>& container) {
    container.sort();
}

// ������������� ��������� �� �������� ��������� ����
void sortDescending(list<Money>& container) {
    container.sort(greater<>());
}

// ����� ������� � ����������
bool findElement(const list<Money>& container, const Money& value) {
    return find(container.begin(), container.end(), value) != container.end();
}

// ��������� ������� �������� ��� ����������
void performTask(list<Money>& container) {
    Money minValue = *min_element(container.begin(), container.end());
    Money maxValue = *max_element(container.begin(), container.end());

    Money difference = maxValue - minValue;

    for (Money& money : container) {
        money = money - difference;
    }
}

#endif  // CONTAINER_OPERATIONS_H
