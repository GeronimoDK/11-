#pragma once
#ifndef VECTOR_H
#define VECTOR_H

#include "date.h"
#include <vector>

class Vector {
public:
    void addDate(Date* date);
    friend std::ostream& operator<<(std::ostream& os, const Vector& vector);

private:
    std::vector<Date*> m_dates;
};

#endif // VECTOR_H