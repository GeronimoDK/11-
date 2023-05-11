#pragma once
#include <stack>
class Set {
private:
	std::stack<int> s; // ���� ��� �������� ��������� ���������
public:
	Set(); // ����������� �� ���������
	Set(const Set& other); // ����������� �����������
	~Set(); // ����������
	void insert(int x); // ���������� �������� � ���������
	void erase(int x); // �������� �������� �� ���������
	bool contains(int x) const; // �������� ������� �������� � ���������
	int size() const; // ������ ���������
	bool empty() const; // �������� �� ������� ���������
	int operator[](int index) const; // ������ �� �������
	bool operator==(const Set& other) const; // �������� �� ���������
	bool operator>(int x) const; // �������� �������������� ����� ���������

	class Iterator { // �����-��������
	private:
		std::stack<int> s;
	public:
		Iterator(std::stack<int> st);
		bool operator!=(const Iterator& other) const;
		int operator*() const;
		Iterator& operator++();
	};

	Iterator begin() const; // �������� �� ������ ���������
	Iterator end() const; // �������� �� ����� ���������
};