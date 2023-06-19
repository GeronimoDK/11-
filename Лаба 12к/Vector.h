// Vector.h
#pragma once
#include <vector>

using namespace std;

// ������������������� ����� Vector
template<typename T>
class Vector {
private:
    vector<T> elements;

public:
    // ����� ��� ���������� �������� � ��������� �� �������� �������
    void addElementAtPosition(T element, int position);

    // ����� ��� �������� �������� �� ���������� � �������� ������
    void removeElementByKey(T key);

    // ����� ��� ���������� ������� ����� ������������ � ����������� ���������� � ��������� �� �� ������� �������� ����������
    void subtractDifference();

    // ����� ��� ������ ����������� ���������� �� �����
    void displayElements();
};
