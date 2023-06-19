#ifndef CONTAINER_OPERATIONS_H
#define CONTAINER_OPERATIONS_H

#include <algorithm>
#include <list>
#include "money.h"

// Заменить элементы в соответствии с заданием
void replaceElements(list<Money>& container, const Money& oldValue, const Money& newValue) {
    replace(container.begin(), container.end(), oldValue, newValue);
}

// Удалить элементы в соответствии с заданием
void removeElements(list<Money>& container, const Money& value) {
    container.remove(value);
}

// Отсортировать контейнер по возрастанию ключевого поля
void sortAscending(list<Money>& container) {
    container.sort();
}

// Отсортировать контейнер по убыванию ключевого поля
void sortDescending(list<Money>& container) {
    container.sort(greater<>());
}

// Найти элемент в контейнере
bool findElement(const list<Money>& container, const Money& value) {
    return find(container.begin(), container.end(), value) != container.end();
}

// Выполнить задание варианта для контейнера
void performTask(list<Money>& container) {
    Money minValue = *min_element(container.begin(), container.end());
    Money maxValue = *max_element(container.begin(), container.end());

    Money difference = maxValue - minValue;

    for (Money& money : container) {
        money = money - difference;
    }
}

#endif  // CONTAINER_OPERATIONS_H
