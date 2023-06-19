// Money.h
#pragma once
#include <iostream>

using namespace std;

// Класс Money для пользовательского типа данных
class Money {
private:
    int rubles;
    int kopeks;

public:
    // Конструктор по умолчанию
    Money();

    // Конструктор с параметрами
    Money(int rub, int kop);

    // Перегрузка оператора ввода
    friend istream& operator>>(istream& is, Money& obj);

    // Перегрузка оператора вывода
    friend ostream& operator<<(ostream& os, const Money& obj);

    // Перегрузка оператора сравнения <
    friend bool operator<(const Money& obj1, const Money& obj2);

    // Перегрузка оператора сравнения >
    friend bool operator>(const Money& obj1, const Money& obj2);

    // Перегрузка оператора сложения
    friend Money operator+(const Money& obj1, const Money& obj2);

    // Перегрузка оператора вычитания
    friend Money operator-(const Money& obj1, const Money& obj2);
};
