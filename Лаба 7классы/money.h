#pragma once
#ifndef MONEY_H
#define MONEY_H
#include <iostream>
using namespace std;
class Money {
public:
	Money(); // ����������� �� ���������
	Money(long rubles, int kopeks); // ����������� � �����������
	long getRubles() const; // ��������� ������
	int getKopeks() const; // ��������� ������

	void setRubles(long rubles); // ��������� ������
	void setKopeks(int kopeks); // ��������� ������

	friend ostream& operator<<(ostream& os, const Money& money); // �������� ������ � �����
	friend istream& operator>>(istream& is, Money& money); // �������� ����� �� ������

	bool operator==(const Money& other) const; // �������� ��������� �� ���������
	bool operator>(double value) const; // �������� �������� �������������� ����� ���������
private:
	long m_rubles; // �����
	int m_kopeks; // �������
};
#endif