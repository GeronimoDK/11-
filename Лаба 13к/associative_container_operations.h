#ifndef ASSOCIATIVE_CONTAINER_OPERATIONS_H
#define ASSOCIATIVE_CONTAINER_OPERATIONS_H

#include <algorithm>
#include <map>
#include <functional>
#include "money.h"

// Заменить элементы в соответствии с заданием
void replaceElements(map<int, Money>& container, const Money& oldValue, const Money& newValue) {
    for (auto& pair : container) {
        if (pair.second == oldValue) {
            pair.second = newValue;
        }
    }
}

// Удалить элементы в соответствии с заданием
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

// Отсортировать контейнер по возрастанию ключевого поля
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

// Отсортировать контейнер по убыванию ключевого поля
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

// Найти элемент в контейнере
bool findElement(const map<int, Money>& container, int key) {
    return container.find(key) != container.end();
}

// Выполнить задание варианта для контейнера
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
