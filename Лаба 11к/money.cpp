#include "money.h"

using namespace std;

Money::Money(int rub, int kop) : rubles(rub), kopecks(kop) {}

void Money::setRubles(int rub) {
    rubles = rub;
}

void Money::setKopecks(int kop) {
    kopecks = kop;
}

int Money::getRubles() const {
    return rubles;
}

int Money::getKopecks() const {
    return kopecks;
}

ostream& operator<<(ostream& os, const Money& money) {
    os << money.rubles << " руб. " << money.kopecks << " коп.";
    return os;
}
