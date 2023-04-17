#pragma once
#ifndef TRIAD_H
#define TRIAD_H

#include <iostream>

class Triad {
public:
    Triad(int first = 0, int second = 0, int third = 0);
    void setFirst(int first);
    void setSecond(int second);
    void setThird(int third);
    int getFirst() const;
    int getSecond() const;
    int getThird() const;
    bool operator==(const Triad& other) const;
    bool operator!=(const Triad& other) const;
    bool operator<(const Triad& other) const;
    bool operator<=(const Triad& other) const;
    bool operator>(const Triad& other) const;
    bool operator>=(const Triad& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Triad& triad);

private:
    int m_first;
    int m_second;
    int m_third;
};

#endif // TRIAD_H
