#include "fraction.h"
#include <iostream>
using namespace std;
fraction make_fraction(double F, int S)
{
	fraction t;//создали временную переменную 

	t.Init(F, S);//инициализировали поля переменной t с помощью параметров функции

	return t;//вернули значение переменной t
}
int main()
{
	setlocale(0, "");

	//определение переменных А и В
	fraction A;
	fraction B;

	A.Init(3, 2);//инициализация переменной А
	A.Show();//вывод значений полей переменной А

	B.Read();//ввод полей переменных В
	B.Show();//вывод значений полей переменной В

	//вывод значения степени, вычисленного с помощью функции Power() 
	cout << "A.Степень(" << A.first << "," << A.second << ")=" << A.Power() << endl;
	cout << "B.Степень(" << B.first << "," << B.second << ")=" << B.Power() << endl;


	//указатели
	fraction* X = new fraction;//выделение памяти под динамическую переменную

	X->Init(2, 5);//инициализация
	X->Show();//вывод значений полей
	X->Power();//вычисление степени

	cout << "X.Степень(" << X->first << "," << X->second << ")=" << X->Power() << endl;


	//массивы
	fraction mas[3];//определение массива

	for (int i = 0; i < 3; i++)
		mas[i].Read();//чтение значений полей

	for (int i = 0; i < 3; i++)
		mas[i].Show(); //вывод значений полей

	for (int i = 0; i < 3; i++)
	{
		mas[i].Power(); //вычисление степени
		cout << "mas[" << i << "].Степень(" << mas[i].first << "," << mas[i].second << ")=";
		cout << mas[i].Power() << endl;
	}

	//динамические масивы
	fraction* p_mas = new fraction[3];//выделение памяти

	for (int i = 0; i < 3; i++)
		p_mas[i].Read();//чтение значений полей

	for (int i = 0; i < 3; i++)
		p_mas[i].Show();//вывод значений полей

	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Power();//вычисление степени
		cout << "p_mas[" << i << "].Степень(" << p_mas[i].first << "," << p_mas[i].second;
		cout << ")=" << p_mas[i].Power() << endl;
	}

	//вызов функции make_fraction()
	double y; int z;

	cout << "Введите первое число: "; cin >> y;
	cout << "Введите второе число: "; cin >> z;

	//переменная F формируется с помощью функции make_fraction()
	fraction F = make_fraction(y, z);
	F.Show();
	return 0;
}