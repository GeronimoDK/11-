#ifndef CONTAINER_ADAPTER_OPERATIONS_H
#define CONTAINER_ADAPTER_OPERATIONS_H

#include <queue>
#include <functional>
#include "money.h"

// Заменить элементы в соответствии с заданием
template <typename T>
void replaceElements(priority_queue<T>& container, const T& oldValue, const T& newValue) {
    priority_queue<T> temp;

    while (!container.empty()) {
        T element = container.top();
        container.pop();

        if (element == oldValue) {
            temp.push(newValue);
        }
        else {
            temp.push(element);
        }
    }

    container = move(temp);
}

// Удалить элементы в соответствии с заданием
template <typename T>
void removeElements(priority_queue<T>& container, const T& value) {
    priority_queue<T> temp;

    while (!container.empty()) {
        T element = container.top();
        container.pop();

        if (element != value) {
            temp.push(element);
        }
    }

    container = move(temp);
}

// Отсортировать контейнер по возрастанию ключевого поля
void sortAscending(priority_queue<Money>& container) {
    vector<Money> temp;
    while (!container.empty()) {
        temp.push_back(container.top());
        container.pop();
    }
    sort(temp.begin(), temp.end());
    for (const auto& item : temp) {
        container.push(item);
    }
}

// Отсортировать контейнер по убыванию ключевого поля
void sortDescending(priority_queue<Money, vector<Money>, greater<Money>>& container) {
    vector<Money> temp;
    while (!container.empty()) {
        temp.push_back(container.top());
        container.pop();
    }
    sort(temp.rbegin(), temp.rend());
    for (const auto& item : temp) {
        container.push(item);
    }
}

// Найти элемент в контейнере
template <typename T>
bool findElement(const priority_queue<T>& container, const T& value) {
    priority_queue<T> temp = container;

    while (!temp.empty()) {
        if (temp.top() == value) {
            return true;
        }

        temp.pop();
    }

    return false;
}

// Выполнить задание варианта для контейнера
template <typename T>
void performTask(priority_queue<T>& container) {
    T minValue = container.top();
    T maxValue = container.top();

    priority_queue<T> temp = container;

    while (!temp.empty()) {
        T element = temp.top();
        temp.pop();

        if (element < minValue) {
            minValue = element;
        }

        if (element > maxValue) {
            maxValue = element;
        }
    }

    T difference = maxValue - minValue;

    priority_queue<T> result;

    while (!container.empty()) {
        T element = container.top();
        container.pop();

        result.push(element - difference);
    }

    container = move(result);
}

#endif  // CONTAINER_ADAPTER_OPERATIONS_H
