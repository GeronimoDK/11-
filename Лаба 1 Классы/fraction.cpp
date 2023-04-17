#include "fraction.h"
#include <iostream>
using namespace std;
//���������� ������ ��� ������������� ����� ���������
void fraction::Init(double F, int S)
{
	first = F; second = S;
}
//���������� ������ ��� ������ �������� ����� ���������
void fraction::Read()
{
	cout << "\n������� ������ �����: "; cin >> first;
	cout << "\n������� ������ �����: "; cin >> second;
}
//���������� ������ ��� ������ �������� ����� ���������
void fraction::Show()
{
	cout << "\n������ ����� =" << first;
	cout << "\n������ ����� =" << second;
	cout << "\n";
}
//����� ��� ���������� � �������
double fraction::Power()
{
	return sqrt(first * first + second * second);
}
