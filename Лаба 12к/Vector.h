// Vector.h
#pragma once
#include <vector>

using namespace std;

// Параметризированный класс Vector
template<typename T>
class Vector {
private:
    vector<T> elements;

public:
    // Метод для добавления элемента в контейнер на заданную позицию
    void addElementAtPosition(T element, int position);

    // Метод для удаления элемента из контейнера с заданным ключом
    void removeElementByKey(T key);

    // Метод для нахождения разницы между максимальным и минимальным элементами и вычитания ее из каждого элемента контейнера
    void subtractDifference();

    // Метод для вывода содержимого контейнера на экран
    void displayElements();
};
