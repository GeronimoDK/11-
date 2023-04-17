#pragma once
#ifndef DATE_H
#define DATE_H

#include "triad.h"

class Date : public Triad {
public:
    Date(int year = 0, int month = 0, int day = 0);
    void setYear(int year);
    void setMonth(int month);
    void setDay(int day);
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator<=(const Date& other) const;
    bool operator>(const Date& other) const;
    bool operator>=(const Date& other) const;

private:
    int m_year;
    int m_month;
    int m_day;
};

#endif // DATE_H