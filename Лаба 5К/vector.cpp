#include "vector.h"

void Vector::addDate(Date* date) {
    m_dates.push_back(date);
}

std::ostream& operator<<(std::ostream& os, const Vector& vector) {
    os << "[ ";
    for (const auto& date : vector.m_dates) {
        os << *date << " ";
    }
    os << "]";
    return os;
}