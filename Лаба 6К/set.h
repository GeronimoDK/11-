#pragma once
#include <iostream>

using namespace std;

    class Set {
    private:
        int* set_array; // динамический массив для хранения элементов множества
        int size; // размер множества
    public:
        // конструкторы
        Set();
        Set(int* array, int array_size);
        Set(const Set& other);

        // деструктор
        ~Set();

        // перегрузка операций ввода-вывода
        friend std::ostream& operator<<(std::ostream& os, const Set& set);
        friend std::istream& operator>>(std::istream& is, Set& set);

        // перегрузка операций присваивания
        Set& operator=(const Set& other);

        // перегрузка операции доступа по индексу
        int& operator[](int index);

        // перегрузка операции проверки на равенство
        bool operator==(const Set& other) const;

        // перегрузка операции принадлежности числа множеству
        bool operator>(int number) const;

        // класс-итератор для последовательного доступа к элементам множества
        class Iterator {
        private:
            int* ptr; // указатель на текущий элемент
        public:
            Iterator(int* p = nullptr) : ptr(p) {}

            // перегрузка операций инкремента и декремента
            Iterator& operator++() { ++ptr; return *this; }
            Iterator& operator--() { --ptr; return *this; }

            // перегрузка операций сравнения
            bool operator==(const Iterator& other) const { return ptr == other.ptr; }
            bool operator!=(const Iterator& other) const { return ptr != other.ptr; }

            // перегрузка операции разыменования
            int& operator*() const { return *ptr; }
        };

        // методы для получения итераторов
        Iterator begin() const { return Iterator(set_array); }
        Iterator end() const { return Iterator(set_array + size); }
    };
