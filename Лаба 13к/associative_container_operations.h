#ifndef ASSOCIATIVE_CONTAINER_OPERATIONS_H
#define ASSOCIATIVE_CONTAINER_OPERATIONS_H

#include <algorithm>
#include <map>
#include <functional>
#include "money.h"

// �������� �������� � ������������ � ��������
void replaceElements(map<int, Money>& container, const Money& oldValue, const Money& newValue) {
    for (auto& pair : container) {
        if (pair.second == oldValue) {
            pair.second = newValue;
        }
    }
}

// ������� �������� � ������������ � ��������
void removeElements(map<int, Money>& container, const Money& value) {
    auto it = container.begin();

    while (it != container.end()) {
        if (it->second == value) {
            it = container.erase(it);
        }
        else {
            ++it;
        }
    }
}

// ������������� ��������� �� ����������� ��������� ����
void sortAscending(map<int, Money>& container) {
    vector<pair<int, Money>> temp(container.begin(), container.end());
    sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
        });
    container.clear();
    for (const auto& pair : temp) {
        container.emplace(pair.first, pair.second);
    }
}

// ������������� ��������� �� �������� ��������� ����
void sortDescending(std::map<int, Money>& container) {
    vector<pair<int, Money>> temp(container.begin(), container.end());
    sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
        });
    container.clear();
    for (const auto& pair : temp) {
        container.emplace(pair.first, pair.second);
    }
}

// ����� ������� � ����������
bool findElement(const map<int, Money>& container, int key) {
    return container.find(key) != container.end();
}

// ��������� ������� �������� ��� ����������
void performTask(map<int, Money>& container) {
    Money minValue = container.begin()->second;
    Money maxValue = container.begin()->second;

    for (const auto& pair : container) {
        const Money& element = pair.second;

        if (element < minValue) {
            minValue = element;
        }

        if (element > maxValue) {
            maxValue = element;
        }
    }

    Money difference = maxValue - minValue;

    for (auto& pair : container) {
        pair.second = pair.second - difference;
    }
}

#endif  // ASSOCIATIVE_CONTAINER_OPERATIONS_H
