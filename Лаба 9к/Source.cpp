#include <iostream>
#include "Set.h"

int main() {
    Set set;
    set.addElement(1);
    set.addElement(2);
    set.addElement(3);

    try {
        std::cout << set[0] << std::endl; // выводим элемент с индексом 0
        std::cout << set[5] << std::endl; // генерируем исключительную ситуацию
    }
    catch (const error& e) {
        std::cout << e.what() << std::endl; // выводим сообщение об ошибке
    }

    Set otherSet;
    otherSet.addElement(1);
    otherSet.addElement(2);
    otherSet.addElement(3);

    std::cout << (set == otherSet) << std::endl; // сравниваем два множества
    std::cout << (set > 4) << std::endl; // проверяем принадлежность числа множеству

    try {
        std::cout << (set - 2) << std::endl; // выводим элемент с номером 2
        std::cout << (set - 5) << std::endl; // генерируем исключительную ситуацию
    }
    catch (const error& e) {
        std::cout << e.what() << std::endl; // выводим сообщение об ошибке
    }

    return 0;
}
