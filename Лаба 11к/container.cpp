#include "container.h"
#include <algorithm>

using namespace std;

void Container::addElement(double element) {
    elements.push_back(element);
}

void Container::removeElement(double element) {
    elements.remove(element);
}

void Container::printElements() {
    cout << "Элементы контейнера: ";
    for (const auto& element : elements) {
        cout << element << " ";
    }
    cout << endl;
}

void Container::taskExecution() {
    if (elements.empty()) {
        cout << "Контейнер пуст." << endl;
        return;
    }

    // Задание 3: Найти элемент с заданным ключом и добавить его на заданную позицию контейнера
    double key = 3.14;
    double position = 2;
    auto it = find(elements.begin(), elements.end(), key);
    if (it != elements.end()) {
        elements.insert(next(elements.begin(), position), *it);
        cout << "Элемент " << key << " добавлен на позицию " << position << endl;
    }
    else {
        cout << "Элемент " << key << " не найден." << endl;
    }

    // Задание 4: Найти элемент с заданным ключом и удалить его из контейнера
    double keyToRemove = 2.71;
    it = find(elements.begin(), elements.end(), keyToRemove);
    if (it != elements.end()) {
        elements.erase(it);
        cout << "Элемент " << keyToRemove << " удален из контейнера." << endl;
    }
    else {
        cout << "Элемент " << keyToRemove << " не найден." << endl;
    }

    // Задание 5: Найти разницу между максимальным и минимальным элементами контейнера
    auto maxElement = max_element(elements.begin(), elements.end());
    auto minElement = min_element(elements.begin(), elements.end());
    if (maxElement != elements.end() && minElement != elements.end()) {
        double diff = *maxElement - *minElement;
        cout << "Разница между максимальным и минимальным элементами: " << diff << endl;

        // Вычитаем разницу из каждого элемента контейнера
        transform(elements.begin(), elements.end(), elements.begin(),
            [diff](double element) { return element - diff; });

        cout << "Элементы контейнера после вычитания разницы: ";
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
    else {
        cout << "Контейнер пуст или содержит только один элемент." << endl;
    }
}
