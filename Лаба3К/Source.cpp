#include <iostream>
using namespace std;

class Money {
private:
    long rub;
    int kop;
public:
    // Конструкторы
    Money() {
        rub = 0;
        kop = 0;
    }
    Money(long r, int k) {
        rub = r;
        kop = k;
    }
    Money(const Money& m) {
        rub = m.rub;
        kop = m.kop;
    }
    // Деструктор
    ~Money() {}
    // Селекторы и модификаторы
    long getRub() const {
        return rub;
    }
    int getKop() const {
        return kop;
    }
    void setRub(long r) {
        rub = r;
    }
    void setKop(int k) {
        kop = k;
    }
    // Перегрузка операции присваивания
    Money& operator=(const Money& m) {
        if (this != &m) {
            rub = m.rub;
            kop = m.kop;
        }
        return *this;
    }
    // Перегрузка операции сложения суммы и дробного числа
    Money operator+(double d) const {
        double sum = rub + (kop / 100.0) + d;
        long r = (long)sum;
        int k = (sum - r) * 100;
        return Money(r, k);
    }
    // Перегрузка операции сравнения
    bool operator>(const Money& m) const {
        if (rub > m.rub) {
            return true;
        }
        else if (rub == m.rub && kop > m.kop) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator<(const Money& m) const {
        if (rub < m.rub) {
            return true;
        }
        else if (rub == m.rub && kop < m.kop) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator==(const Money& m) const {
        if (rub == m.rub && kop == m.kop) {
            return true;
        }
        else {
            return false;
        }
    }
    // Перегрузка операций ввода и вывода объектов с помощью потоков
    friend istream& operator>>(istream& is, Money& m) {
        char c;
        is >> m.rub >> c >> m.kop;
        return is;
    }
    friend ostream& operator<<(ostream& os, const Money& m) {
        os << m.rub << "," << (m.kop < 10 ? "0" : "") << m.kop;
        return os;
    }
};

int main() {
    Money m1(100, 50);
    Money m2(200, 25);
    cout << "m1 = " << m1 << endl;
    cout << "m2 = " << m2 << endl;
    Money m3 = m1 + 12.75;
    cout << "m3 = " << m3 << endl;
    cout << "m2 > m1: " << (m2 > m1 ? "true" : "false") << endl;
    cout << "m2 < m1: " << (m2 < m1 ? "true" : "false") << endl;
    cout << "m1 == m3: " << (m1 == m3 ? "true" : "false") << endl;
    return 0;
}
