#include "set.h"
Set::Set() {}
Set::Set(const Set& other) {
	s = other.s;
}
Set::~Set() {}
void Set::insert(int x) {
	if (!contains(x)) {
		s.push(x);
	}
}
void Set::erase(int x) {
	std::stack<int> temp;
	while (!s.empty()) {
		int top = s.top();
		s.pop();
		if (top != x) {
			temp.push(top);
		}
	}
	while (!temp.empty()) {
		int top = temp.top();
		temp.pop();
		s.push(top);
	}
}
bool Set::contains(int x) const {
	std::stack<int> temp = s;
	while (!temp.empty()) {
		int top = temp.top();
		temp.pop();
		if (top == x) {
			return true;
		}
	}
	return false;
}
int Set::size() const {
	return s.size();
}
bool Set::empty() const {
	return s.empty();
}
int Set::operator[](int index) const {
	std::stack<int> temp = s;
	int i = 0;
	while (!temp.empty()) {
		int top = temp.top();
		temp.pop();
		if (i == index) {
			return top;
		}
		i++;
	}
	return -1;
}
bool Set::operator==(const Set& other) const {
	if (size() != other.size()) {
		return false;
	}
	std::stack<int> temp1 = s;
	std::stack<int> temp2 = other.s;
	while (!temp1.empty()) {
		int top1 = temp1.top();
		temp1.pop();
		int top2 = temp2.top();
		temp2.pop();
		if (top1 != top2) {
			return false;
		}
	}
	return true;
}
bool Set::operator>(int x) const {
	return contains(x);
}
Set::Iterator::Iterator(std::stack<int> st) {
	s = st;
}
bool Set::Iterator::operator!=(const Iterator& other) const {
	return s != other.s;
}
int Set::Iterator::operator*() const {
	return s.top();
}
Set::Iterator& Set::Iterator::operator++() {
	s.pop();
	return *this;
}
Set::Iterator Set::begin() const {
	return Iterator(s);
}
Set::Iterator Set::end() const {
	std::stack<int> temp = s;
	while (!temp.empty()) {
		temp.pop();
	}
	return Iterator(temp);
}