#pragma once
#include <iostream>
#include <vector>
using namespace std;
template <class T> //T - �������� �������
class Set {
public:
	Set(); // ����������� �� ���������
	Set(const Set<T>& other); // ����������� �����������
	~Set(); // ����������
	void insert(const T& value); // ���������� �������� � ���������
	void remove(const T& value); // �������� �������� �� ���������
	bool contains(const T& value) const; // �������� ������� �������� � ���������
	int size() const; // ��������� ������� ���������

	T& operator[](int index); // ������ � �������� �� �������
	const T& operator[](int index) const; // ������ � �������� �� ������� (�����������)
	Set<T>& operator=(const Set<T>& other); // �������� ������������
	bool operator==(const Set<T>& other) const; // �������� ��������� �� ���������
	bool operator>(const T& value) const; // �������� �������� �������������� ����� ���������

	template <class U>
	friend ostream& operator<<(ostream& os, const Set<U>& set); // �������� ������ � �����
private:
	vector<T> m_data; // ������ ��� �������� ��������� ���������
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