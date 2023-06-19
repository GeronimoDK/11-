#pragma once
#include <iostream>
using namespace std;

class Money {
private:
    int rubles;
    int kopecks;

public:
    Money(int rub, int kop);
    void setRubles(int rub);
    void setKopecks(int kop);
    int getRubles() const;
    int getKopecks() const;
    friend ostream& operator<<(ostream& os, const Money& money);
};
