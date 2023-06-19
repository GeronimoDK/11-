#include "error.h"

class Set {
private:
    int* elements; // ������ ��������� ���������
    int size; // ������ ���������

public:
    Set() : elements(nullptr), size(0) {}

    ~Set() {
        delete[] elements;
    }

    void addElement(int element) {
        int* newElements = new int[size + 1];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        newElements[size] = element;

        delete[] elements;
        elements = newElements;
        size++;
    }

    // �������� ������� �� �������
    int operator[](int index) const {
        if (index < 0 || index >= size) {
            throw error();
        }
        return elements[index];
    }

    // �������� �������� �� ���������
    bool operator==(const Set& other) const {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (elements[i] != other.elements[i]) {
                return false;
            }
        }
        return true;
    }

    // �������� �������������� ����� ���������
    bool operator>(int number) const {
        for (int i = 0; i < size; i++) {
            if (elements[i] == number) {
                return true;
            }
        }
        return false;
    }

    // �������� �������� ����� � �������� � ������� n
    int operator-(int n) const {
        if (n < 0 || n >= size) {
            throw error();
        }
        return elements[n];
    }
};
