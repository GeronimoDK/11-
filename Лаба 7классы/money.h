#pragma once
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
using namespace std;
class Money {
public:
	Money(); // конструктор по умолчанию
	Money(long rubles, int kopeks); // конструктор с параметрами
	long getRubles() const; // получение рублей
	int getKopeks() const; // получение копеек

	void setRubles(long rubles); // установка рублей
	void setKopeks(int kopeks); // установка копеек

	friend ostream& operator<<(ostream& os, const Money& money); // оператор вывода в поток
	friend istream& operator>>(istream& is, Money& money); // оператор ввода из потока

	bool operator==(const Money& other) const; // оператор сравнения на равенство
	bool operator>(double value) const; // оператор проверки принадлежности числа множеству
private:
	long m_rubles; // рубли
	int m_kopeks; // копейки
};
#endif