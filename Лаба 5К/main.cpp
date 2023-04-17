#include "vector.h"
#include <iostream>

int main() {
    Date date1(2021, 4, 13);
    Date date2(2022, 4, 13);
    Date date3(2022, 5, 13);

    std::cout << "date1 == date2: " << (date1 == date2) << std::endl;
    std::cout << "date2 != date3: " << (date2 != date3) << std::endl;
    std::cout << "date1 < date2: " << (date1 < date2) << std::endl;
    std::cout << "date1 <= date2: " << (date1 <= date2) << std::endl;
    std::cout << "date2 > date3: " << (date2 > date3) << std::endl;
    std::cout << "date2 >= date3: " << (date2 >= date3) << std::endl;

    Vector vector;
    vector.addDate(&date1);
    vector.addDate(&date2);
    vector.addDate(&date3);

    std::cout << "Vector: " << vector << std::endl;

    return 0;
}