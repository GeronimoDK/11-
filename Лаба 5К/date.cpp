#include "date.h"

Date::Date(int year, int month, int day)
    : Triad(year, month, day), m_year(year), m_month(month), m_day(day)
{}

void Date::setYear(int year) {
    Triad::setFirst(year);
    m_year = year;
}

void Date::setMonth(int month) {
    Triad::setSecond(month);
    m_month = month;
}

void Date::setDay(int day) {
    Triad::setThird(day);
    m_day = day;
}

int Date::getYear() const {
    return m_year;
}

int Date::getMonth() const {
    return m_month;
}

int Date::getDay() const {
    return m_day;
}

bool Date::operator==(const Date& other) const {
    return Triad::operator==(other);
}

bool Date::operator!=(const Date& other) const {
    return Triad::operator!=(other);
}

bool Date::operator<(const Date& other) const {
    if (m_year < other.m_year) {
        return true;
    }
    else if (m_year > other.m_year) {
        return false;
    }
    else {
        if (m_month < other.m_month) {
            return true;
        }
        else if (m_month > other.m_month) {
            return false;
        }
        else {
            return m_day < other.m_day;
        }
    }
}

bool Date::operator<=(const Date& other) const {
    return *this < other || *this == other;
}

bool Date::operator>(const Date& other) const {
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    return !(*this < other);
}