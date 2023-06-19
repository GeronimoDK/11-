#include <iostream>
#include "Set.h"

int main() {
    Set set;
    set.addElement(1);
    set.addElement(2);
    set.addElement(3);

    try {
        std::cout << set[0] << std::endl; // ������� ������� � �������� 0
        std::cout << set[5] << std::endl; // ���������� �������������� ��������
    }
    catch (const error& e) {
        std::cout << e.what() << std::endl; // ������� ��������� �� ������
    }

    Set otherSet;
    otherSet.addElement(1);
    otherSet.addElement(2);
    otherSet.addElement(3);

    std::cout << (set == otherSet) << std::endl; // ���������� ��� ���������
    std::cout << (set > 4) << std::endl; // ��������� �������������� ����� ���������

    try {
        std::cout << (set - 2) << std::endl; // ������� ������� � ������� 2
        std::cout << (set - 5) << std::endl; // ���������� �������������� ��������
    }
    catch (const error& e) {
        std::cout << e.what() << std::endl; // ������� ��������� �� ������
    }

    return 0;
}
