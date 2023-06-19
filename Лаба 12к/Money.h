// Money.h
#pragma once
#include <iostream>

using namespace std;

// ����� Money ��� ����������������� ���� ������
class Money {
private:
    int rubles;
    int kopeks;

public:
    // ����������� �� ���������
    Money();

    // ����������� � �����������
    Money(int rub, int kop);

    // ���������� ��������� �����
    friend istream& operator>>(istream& is, Money& obj);

    // ���������� ��������� ������
    friend ostream& operator<<(ostream& os, const Money& obj);

    // ���������� ��������� ��������� <
    friend bool operator<(const Money& obj1, const Money& obj2);

    // ���������� ��������� ��������� >
    friend bool operator>(const Money& obj1, const Money& obj2);

    // ���������� ��������� ��������
    friend Money operator+(const Money& obj1, const Money& obj2);

    // ���������� ��������� ���������
    friend Money operator-(const Money& obj1, const Money& obj2);
};
