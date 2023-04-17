#include "triad.h"

Triad::Triad(int first, int second, int third)
    : m_first(first), m_second(second), m_third(third)
{}

void Triad::setFirst(int first) {
    m_first = first;
}

void Triad::setSecond(int second) {
    m_second = second;
}

void Triad::setThird(int third) {
    m_third = third;
}

int Triad::getFirst() const {
    return m_first;
}

int Triad::getSecond() const {
    return m_second;
}

int Triad::getThird() const {
    return m_third;
}

bool Triad::operator==(const Triad& other) const {
    return m_first == other.m_first && m_second == other.m_second && m_third == other.m_third;
}

bool Triad::operator!=(const Triad& other) const {
    return !(*this == other);
}

bool Triad::operator<(const Triad& other) const {
    if (m_first < other.m_first) {
        return true;
    }
    else if (m_first > other.m_first) {
        return false;
    }
    else {
        if (m_second < other.m_second) {
            return true;
        }
        else if (m_second > other.m_second) {
            return false;
        }
        else {
            return m_third < other.m_third;
        }
    }
}

bool Triad::operator<=(const Triad& other) const {
    return *this < other || *this == other;
}

bool Triad::operator>(const Triad& other) const {
    return !(*this <= other);
}

bool Triad::operator>=(const Triad& other) const {
    return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const Triad& triad) {
    os << "(" << triad.m_first << ", " << triad.m_second << ", " << triad.m_third << ")";
    return os;
}
