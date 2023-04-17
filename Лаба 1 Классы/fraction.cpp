#include "fraction.h"
#include <iostream>
using namespace std;
//реализация метода для инициализации полей структуры
void fraction::Init(double F, int S)
{
	first = F; second = S;
}
//реализация метода для чтения значений полей структуры
void fraction::Read()
{
	cout << "\nВведите первое число: "; cin >> first;
	cout << "\nВведите второе число: "; cin >> second;
}
//реализация метода для вывода значений полей структуры
void fraction::Show()
{
	cout << "\nПервое число =" << first;
	cout << "\nВторое число =" << second;
	cout << "\n";
}
//метод для возведения в степень
double fraction::Power()
{
	return sqrt(first * first + second * second);
}
