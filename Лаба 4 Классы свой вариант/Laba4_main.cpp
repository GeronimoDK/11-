#include <iostream>
using namespace std;

// базовый класс
class Triad {
protected:
    int first, second, third;

public:
    // конструктор без параметров
    Triad() {
        first = 0;
        second = 0;
        third = 0;
    }

    // конструктор с параметрами
    Triad(int f, int s, int t) {
        first = f;
        second = s;
        third = t;
    }

    // конструктор копирования
    Triad(const Triad& obj) {
        first = obj.first;
        second = obj.second;
        third = obj.third;
    }

    // деструктор
    ~Triad() {}

    // селекторы и модификаторы
    int getFirst() const { return first; }
    int getSecond() const { return second; }
    int getThird() const { return third; }
    void setFirst(int f) { first = f; }
    void setSecond(int s) { second = s; }
    void setThird(int t) { third = t; }

    // перегрузка операции присваивания
    Triad& operator=(const Triad& obj) {
        if (this != &obj) {
            first = obj.first;
            second = obj.second;
            third = obj.third;
        }
        return *this;
    }

    // перегрузка операций ввода и вывода
    friend istream& operator>>(istream& in, Triad& obj) {
        cout << "Введите первое число: ";
        in >> obj.first;
        cout << "Введите второе число: ";
        in >> obj.second;
        cout << "Введите третье число: ";
        in >> obj.third;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Triad& obj) {
        out << obj.first << ", " << obj.second << ", " << obj.third;
        return out;
    }

    // методы изменения полей и сравнения триады
    
    bool isEqual(const Triad& obj) const {
        return (first == obj.first && second == obj.second && third == obj.third);
    }
};

// производный класс
class Date : public Triad {
public:
    // конструктор без параметров
    Date() : Triad() {}

    // конструктор с параметрами
    Date(int year, int month, int day) : Triad(year, month, day) {}

    // конструктор копирования
    Date(const Date& obj) : Triad(obj.first, obj.second, obj.third) {}

    // перегрузка операции присваивания
    Date& operator=(const Date& obj) {
        if (this != &obj) {
            first = obj.first;
            second = obj.second;
            third = obj.third;
        }
        return *this;
    }

    // перегрузка операций ввода и вывода
    friend istream& operator>>(istream& in, Date& obj) {
        cout << "Введите год: ";
        in >> obj.first;
        cout << "Введите месяц: ";
        in >> obj.second;
        cout << "Введите день: ";
        in >> obj.third;
        return in;
    }
    friend ostream& operator<<(ostream& out, const Date& obj) {
        out << obj.first << "/" << obj.second << "/" << obj.third;
        return out;
    }

    // операции сравнения дат
    bool operator==(const Date& obj) const {
        return (first == obj.first && second == obj.second && third == obj.third);
    }
    bool operator!=(const Date& obj) const {
        return !(*this == obj);
    }
    bool operator>(const Date& obj) const {
        if (first > obj.first) {
            return true;
        }
        else if (first == obj.first) {
            if (second > obj.second) {
                return true;
            }
            else if (second == obj.second) {
                if (third > obj.third) {
                    return true;
                }
            }
        }
        return false;
    }
    bool operator<(const Date& obj) const {
        return (!(*this > obj) && !(*this == obj));
    }
    bool operator>=(const Date& obj) const {
        return (*this > obj || *this == obj);
    }
    bool operator<=(const Date& obj) const {
        return (*this < obj || *this == obj);
    }
};

// функции, получающие и возвращающие объект базового класса
Triad run(Triad obj) {
       return obj;
}
void print(const Triad& obj) {
    cout << obj << endl;
}

int main() {

    setlocale(0, "");

    // создание объектов и работа со всеми перегруженными операциями
    Triad obj1;                        // конструктор без параметров
    Triad obj2(1, 2, 3);               // конструктор с параметрами
    Triad obj3 = obj2;                 // конструктор копирования
    Triad obj4;
    obj4 = obj1;                       // перегрузка операции присваивания

    cout << "Введите триаду: ";
    cin >> obj1;                       // перегрузка операции ввода
    cout << "Триада: " << obj1 << endl; // перегрузка операции вывода

 
    cout << obj3 << " - Заданная триада" << endl;// метод изменения полей

    if (obj2.isEqual(obj4) == 1)
        cout << "Триады равны" << endl;
    else cout << "Триады НЕ равны" << endl;// метод сравнения триады

    Date date1;
    Date date2(2021, 10, 1);
    cout << "Введите дату: ";
    cin >> date1;

    // операции сравнения дат
    if (date1 == date2) {
        cout << "Даты равны" << endl;
    }
    else if (date1 != date2) {
        cout << "Даты не равны" << endl;
    }

    if (date1 > date2) {
        cout << "Дата 1 позже чем дата 2" << endl;
    }
    else if (date1 < date2) {
        cout << "Дата 1 раньше чем дата 2" << endl;
    }

    //if (date1 >= date2) {
    //    cout << "Дата 1 позже или равна дате 2" << endl;
    //}
    //else if (date1 <= date2) {
    //    cout << "Дата 1 раньше или равна дате 2" << endl;
    //}

    // принцип подстановки
    print(date1);
    Triad obj5 = run(date2);
    cout << obj5 << " - Заданная дата" << endl;

    return 0;
}