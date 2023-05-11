#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <class T> //T - параметр шаблона
class Set {
public:
	Set(); // конструктор по умолчанию
	Set(const Set<T>& other); // конструктор копирования
	~Set(); // деструктор
	void insert(const T& value); // добавление элемента в множество
	void remove(const T& value); // удаление элемента из множества
	bool contains(const T& value) const; // проверка наличия элемента в множестве
	int size() const; // получение размера множества

	T& operator[](int index); // доступ к элементу по индексу
	const T& operator[](int index) const; // доступ к элементу по индексу (константный)
	Set<T>& operator=(const Set<T>& other); // оператор присваивания
	bool operator==(const Set<T>& other) const; // оператор сравнения на равенство
	bool operator>(const T& value) const; // оператор проверки принадлежности числа множеству

	template <class U>
	friend ostream& operator<<(ostream& os, const Set<U>& set); // оператор вывода в поток
private:
	vector<T> m_data; // вектор для хранения элементов множества
};
template <class T>
Set<T>::Set() {}

template <class T>
Set<T>::Set(const Set<T>& other) {
	m_data = other.m_data;
}
template <class T>
Set<T>::~Set() {}
template <class T>
void Set<T>::insert(const T& value) {
	if (!contains(value)) {
		m_data.push_back(value);
	}
}
template <class T>
void Set<T>::remove(const T& value) {
	for (int i = 0; i < m_data.size(); i++) {
		if (m_data[i] == value) {
			m_data.erase(m_data.begin() + i);
			break;
		}
	}
}
template <class T>
bool Set<T>::contains(const T& value) const {
	for (int i = 0; i < m_data.size(); i++) {
		if (m_data[i] == value) {
			return true;
		}
	}
	return false;
}
template <class T>
int Set<T>::size() const {
	return m_data.size();
}
template <class T>
T& Set<T>::operator[](int index) {
	return m_data[index];
}
template <class T>
const T& Set<T>::operator[](int index) const {
	return m_data[index];
}
template <class T>
Set<T>& Set<T>::operator=(const Set<T>& other) {
	m_data = other.m_data;
	return *this;
}
template <class T>
bool Set<T>::operator==(const Set<T>& other) const {
	if (m_data.size() != other.m_data.size()) {
		return false;
	}
	for (int i = 0; i < m_data.size(); i++) {
		if (!other.contains(m_data[i])) {
			return false;
		}
	}
	return true;
}
template <class T>
bool Set<T>::operator>(const T& value) const {
	for (int i = 0; i < m_data.size(); i++) {
		if (m_data[i] == value) {
			return true;
		}
	}
	return false;
}
template <class U>
ostream& operator<<(ostream& os, const Set<U>& set) {
	os << "{";
	for (int i = 0; i < set.m_data.size(); i++) {
		os << set.m_data[i];
		if (i != set.m_data.size() - 1) {
			os << ", ";
		}
	}
	os << "}";
	return os;
}