#pragma once
#include <iostream>

using namespace std;

    class Set {
    private:
        int* set_array; // ������������ ������ ��� �������� ��������� ���������
        int size; // ������ ���������
    public:
        // ������������
        Set();
        Set(int* array, int array_size);
        Set(const Set& other);

        // ����������
        ~Set();

        // ���������� �������� �����-������
        friend std::ostream& operator<<(std::ostream& os, const Set& set);
        friend std::istream& operator>>(std::istream& is, Set& set);

        // ���������� �������� ������������
        Set& operator=(const Set& other);

        // ���������� �������� ������� �� �������
        int& operator[](int index);

        // ���������� �������� �������� �� ���������
        bool operator==(const Set& other) const;

        // ���������� �������� �������������� ����� ���������
        bool operator>(int number) const;

        // �����-�������� ��� ����������������� ������� � ��������� ���������
        class Iterator {
        private:
            int* ptr; // ��������� �� ������� �������
        public:
            Iterator(int* p = nullptr) : ptr(p) {}

            // ���������� �������� ���������� � ����������
            Iterator& operator++() { ++ptr; return *this; }
            Iterator& operator--() { --ptr; return *this; }

            // ���������� �������� ���������
            bool operator==(const Iterator& other) const { return ptr == other.ptr; }
            bool operator!=(const Iterator& other) const { return ptr != other.ptr; }

            // ���������� �������� �������������
            int& operator*() const { return *ptr; }
        };

        // ������ ��� ��������� ����������
        Iterator begin() const { return Iterator(set_array); }
        Iterator end() const { return Iterator(set_array + size); }
    };
