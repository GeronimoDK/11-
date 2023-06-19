#pragma once
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Vector {
private:
    vector<T> elements;

public:
    void addElement(const T& element);
    void removeElement(const T& element);
    void printElements();
    void taskExecution();
};

template<typename T>
void Vector<T>::addElement(const T& element) {
    elements.push_back(element);
}

template<typename T>
void Vector<T>::removeElement(const T& element) {
    elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
}

template<typename T>
void Vector<T>::printElements() {
    cout << "Элементы вектора: ";
    for (const auto& element : elements) {
        cout << element << " ";
    }
    cout << endl;
}

template<typename T>
void Vector<T>::taskExecution() {
    if (elements.empty()) {
        cout << "Вектор пуст." << endl;
        return;
    }

    // Задание 3: Найти элемент с заданным ключом и добавить его на заданную позицию вектора
    T key = T(42);  // Пример использования конструктора для пользовательского типа
    size_t position = 2;
    auto it = find(elements.begin(), elements.end(), key);
    if (it != elements.end()) {
        elements.insert(elements.begin() + position, *it);
        cout << "Элемент " << key << " добавлен на позицию " << position << endl;
    }
    else {
        cout << "Элемент " << key << " не найден." << endl;
    }

    // Задание 4: Найти элемент с заданным ключом и удалить его из вектора
    T keyToRemove = T(24);
    it = find(elements.begin(), elements.end(), keyToRemove);
    if (it != elements.end()) {
        elements.erase(it);
        cout << "Элемент " << keyToRemove << " удален из вектора." << endl;
    }
    else {
        cout << "Элемент " << keyToRemove << " не найден." << endl;
    }

    // Задание 5: Найти разницу между максимальным и минимальным элементами вектора
    auto maxElement = max_element(elements.begin(), elements.end());
    auto minElement = min_element(elements.begin(), elements.end());
    if (maxElement != elements.end() && minElement != elements.end()) {
        T diff = *maxElement - *minElement;
        cout << "Разница между максимальным и минимальным элементами: " << diff << endl;

        // Вычитаем разницу из каждого элемента вектора
        transform(elements.begin(), elements.end(), elements.begin(),
            [diff](const T& element) { return element - diff; });

        cout << "Элементы вектора после вычитания разницы: ";
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
    else {
        cout << "Вектор пуст или содержит только один элемент." << endl;
    }
}
