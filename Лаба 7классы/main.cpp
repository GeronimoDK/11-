#include <iostream>
#include "set.h"
#include "money.h"
using namespace std;
int main() {
	// Инстанцирование шаблона для стандартных типов данных
	Set<int> intSet;
	intSet.insert(1);
	intSet.insert(2);
	intSet.insert(3);
	cout << "intSet: " << intSet << endl;
	cout << "intSet[1]: " << intSet[1] << endl;
	cout << "intSet > 2: " << (intSet > 2) << endl;
	// Инстанцирование шаблона для пользовательского класса
	Set<Money> moneySet;
	Money m1(10, 50);
	Money m2(20, 75);
	Money m3(30, 50);
	moneySet.insert(m1);
	moneySet.insert(m2);
	cout << "moneySet: " << moneySet << endl;
	cout << "moneySet[1]: " << moneySet[1] << endl;
	cout << "m1 == m3: " << (m1 == m3) << endl;
	cout << "m2 > 15.00: " << (m2 > 15.00) << endl;

	return 0;
}