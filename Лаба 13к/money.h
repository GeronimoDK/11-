#ifndef MONEY_H
#define MONEY_H

#include <iostream>
using namespace std;

class Money {
public:
    Money(int dollars, int cents) : dollars_(dollars), cents_(cents) {}

    int getDollars() const {
        return dollars_;
    }

    int getCents() const {
        return cents_;
    }

    void setDollars(int dollars) {
        dollars_ = dollars;
    }

    void setCents(int cents) {
        cents_ = cents;
    }

    bool operator==(const Money& other) const {
        return dollars_ == other.dollars_ && cents_ == other.cents_;
    }

    bool operator!=(const Money& other) const {
        return !(*this == other);
    }

    bool operator<(const Money& other) const {
        if (dollars_ < other.dollars_) {
            return true;
        }
        else if (dollars_ > other.dollars_) {
            return false;
        }
        else {
            return cents_ < other.cents_;
        }
    }

    bool operator>(const Money& other) const {
        return other < *this;
    }

    bool operator<=(const Money& other) const {
        return !(*this > other);
    }

    bool operator>=(const Money& other) const {
        return !(*this < other);
    }

    Money operator+(const Money& other) const {
        int totalCents = cents_ + other.cents_;
        int dollarsOverflow = totalCents / 100;
        int remainingCents = totalCents % 100;

        int totalDollars = dollars_ + other.dollars_ + dollarsOverflow;

        return Money(totalDollars, remainingCents);
    }

    Money operator-(const Money& other) const {
        int totalCents = cents_ - other.cents_;
        int dollarsBorrow = 0;

        if (totalCents < 0) {
            totalCents += 100;
            dollarsBorrow = 1;
        }

        int totalDollars = dollars_ - other.dollars_ - dollarsBorrow;

        return Money(totalDollars, totalCents);
    }

    friend ostream& operator<<(std::ostream& os, const Money& money);

private:
    int dollars_;
    int cents_;
};

std::ostream& operator<<(ostream& os, const Money& money) {
    os << "$" << money.getDollars() << "." << money.getCents();
    return os;
}

#endif  // MONEY_H
