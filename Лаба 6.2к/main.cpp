#include "set.h"
#include <iostream>
int main()
{
	Set s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	Set s2;
	s2.insert(3);
	s2.insert(2);
	s2.insert(1);

	std::cout << (s1 == s2) << std::endl; // ������� 1, �.�. ��������� �����

	std::cout << (s1 > 2) << std::endl; // ������� 1, �.�. 2 ����������� �������� s1

	for (Set::Iterator it = s1.begin(); it != s1.end(); ++it) { // ����� ��������� ���������
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}