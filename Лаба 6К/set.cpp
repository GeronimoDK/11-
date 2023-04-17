#include "set.h"

    // ����������� �� ���������
    Set::Set() : set_array(nullptr), size(0) {}

    // ����������� � �����������
    Set::Set(int* array, int array_size) {
        // �������� ������ ��� �������� ��������� ���������
        size = 0;
        set_array = new int[array_size];
        // ��������� �������� � ���������, ���� �� ��� ��� ���
        for (int i = 0; i < array_size; i++) {
            bool exists = false;
            for (int j = 0; j < size; j++) {
                if (array[i] == set_array[j]) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                set_array[size] = array[i];
                size++;
            }
        }
    }

    // ����������� �����������
    Set::Set(const Set& other) {
        // �������� ������ ��� �������� ��������� ���������
        size = other.size;
        set_array = new int[size];
        // �������� �������� ���������
        for (int i = 0; i < size; i++) {
            set_array[i] = other.set_array[i];
        }
    }

    // ����������
    Set::~Set() {
        delete[] set_array;
    }

    // ���������� �������� �����-������
    std::ostream& operator<<(std::ostream& os, const Set& set) {
        os << "{";
        for (int i = 0; i < set.size; i++) {
            os << set.set_array[i];
            if (i != set.size - 1) {
                os << ", ";
            }
        }
        os << "}";
        return os;
    }

    std::istream& operator>>(std::istream& is, Set& set) {
        // ��������� �������� ���������
        int element;
        is >> element;
        while (is) {
            bool exists = false;
            for (int i = 0; i < set.size; i++) {
                if (element == set.set_array[i]) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                int* new_set_array = new int[set.size + 1];
                for (int i = 0; i < set.size; i++) {
                    new_set_array[i] = set.set_array[i];
                }
                new_set_array[set.size] = element;
                delete[] set.set_array;
                set.set_array = new_set_array;
                set.size++;
            }
            is >> element;
        }
        return is;
    }

    // ���������� �������� ������������
    Set& Set::operator=(const Set& other) {
        // �������� �� ����������������
        if (this == &other) {
            return *this;
        }
        // ����������� ������ ������ � �������� �����
        delete[] set_array;
        size = other.size;
        set_array = new int[size];
        // �������� �������� ���������
        for (int i = 0; i < size; i++) {
            set_array[i] = other.set_array[i];
        }
        return *this;
    }

    // ���������� �������� ������� �� �������
    int& Set::operator[](int index) {
        return set_array[index];
    }

    // ���������� �������� �������� �� ���������
    bool Set::operator==(const Set& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            bool exists = false;
            for (int j = 0; j < other.size; j++) {
                if (set_array[i] == other.set_array[j]) {
                    exists = true;
                    break;
                }
            }
            if (!exists) {
                return false;
            }
        }
        return true;
    }

    // ���������� �������� �������������� ����� ���������
    bool Set::operator>(int number) const {
        for (int i = 0; i < size; i++) {
            if (set_array[i] == number) {
                return true;
            }
        }
        return false;
    }