#pragma once
#include <stack>
class Set {
private:
	std::stack<int> s; // стек для хранения элементов множества
public:
	Set(); // конструктор по умолчанию
	Set(const Set& other); // конструктор копирования
	~Set(); // деструктор
	void insert(int x); // добавление элемента в множество
	void erase(int x); // удаление элемента из множества
	bool contains(int x) const; // проверка наличия элемента в множестве
	int size() const; // размер множества
	bool empty() const; // проверка на пустоту множества
	int operator[](int index) const; // доступ по индексу
	bool operator==(const Set& other) const; // проверка на равенство
	bool operator>(int x) const; // проверка принадлежности числа множеству

	class Iterator { // класс-итератор
	private:
		std::stack<int> s;
	public:
		Iterator(std::stack<int> st);
		bool operator!=(const Iterator& other) const;
		int operator*() const;
		Iterator& operator++();
	};

	Iterator begin() const; // итератор на начало множества
	Iterator end() const; // итератор на конец множества
};