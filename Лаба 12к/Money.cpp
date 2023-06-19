// Money.cpp
#include "Money.h"

Money::Money() : rubles(0), kopeks(0) {}

Money::Money(int rub, int kop) : rubles(rub), kopeks(kop) {}

istream& operator>>(istream& is, Money& obj) {
    cout << "Введите сумму (рубли и копейки через пробел): ";
    is >> obj.rubles >> obj.kopeks;
    return is;
}

ostream& operator<<(ostream& os, const Money& obj) {
    os << obj.rubles << " руб. " << obj.kopeks << " коп.";
    return os;
}

bool operator<(const Money& obj1, const Money& obj2) {
    return (obj1.rubles < obj2.rubles) || (obj1.rubles == obj2.rubles && obj1.kopeks < obj2.kopeks);
}

bool operator>(const Money& obj1, const Money& obj2) {
    return (obj1.rubles > obj2.rubles) || (obj1.rubles == obj2.rubles && obj1.kopeks > obj2.kopeks);
}

Money operator+(const Money& obj1, const Money& obj2) {
    Money result;
    result.rubles = obj1.rubles + obj2.rubles;
    result.kopeks = obj1.kopeks + obj2.kopeks;
    if (result.kopeks >= 100) {
        result.rubles += result.kopeks / 100;
        result.kopeks %= 100;
    }
    return result;
}

Money operator-(const Money& obj1, const Money& obj2) {
    Money result;
    result.rubles = obj1.rubles - obj2.rubles;
    result.kopeks = obj1.kopeks - obj2.kopeks;
    if (result.kopeks < 0) {
        result.rubles -= 1;
        result.kopeks += 100;
    }
    return result;
}
