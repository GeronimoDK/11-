// Vector.cpp
#include "Vector.h"
#include <iostream>

template<typename T>
void Vector<T>::addElementAtPosition(T element, int position) {
    elements.insert(elements.begin() + position, element);
}

template<typename T>
void Vector<T>::removeElementByKey(T key) {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (*it == key) {
            elements.erase(it);
            break;
        }
    }
}

template<typename T>
void Vector<T>::subtractDifference() {
    if (!elements.empty()) {
        T maxElement = elements[0];
        T minElement = elements[0];

        for (const auto& element : elements) {
            if (element > maxElement) {
                maxElement = element;
            }
            if (element < minElement) {
                minElement = element;
            }
        }

        T difference = maxElement - minElement;
        for (auto& element : elements) {
            element -= difference;
        }
    }
}

template<typename T>
void Vector<T>::displayElements() {
    for (const auto& element : elements) {
        cout << element << " ";
    }
    cout << endl;
}

// Явное инстанцирование шаблонного класса для типа double
template class Vector<double>;
