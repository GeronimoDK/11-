#include <iostream>
#include <string>

using namespace std;

class Apartment {
private:
    string address; // Адрес квартиры
    double area;    // Площадь квартиры
    int rooms;      // Количество комнат в квартире

public:
    // Конструктор без параметров
    Apartment() {
        address = "";
        area = 0.0;
        rooms = 0;
    }

    // Конструктор с параметрами
    Apartment(string ad, double ar, int r) {
        address = ad;
        area = ar;
        rooms = r;
    }

    // Конструктор копирования
    Apartment(const Apartment& ap) {
        address = ap.address;
        area = ap.area;
        rooms = ap.rooms;
    }

    // Деструктор
    ~Apartment() {}

    // Селекторы и модификаторы
    string getAddress() {
        return address;
    }

    void setAddress(string ad) {
        address = ad;
    }

    double getArea() {
        return area;
    }

    void setArea(double ar) {
        area = ar;
    }

    int getRooms() {
        return rooms;
    }

    void setRooms(int r) {
        rooms = r;
    }
};

int main() {
    setlocale(0, "");

    // Создание объектов с помощью разных конструкторов
    Apartment a1;   // Объект, созданный с помощью конструктора без параметров
    Apartment a2("ул. Пушкина, дом Колотушкина, кв. 13", 25.5, 1); // Объект, созданный с помощью конструктора с параметрами
    Apartment a3 = a2;  // Объект, созданный с помощью конструктора копирования

    // Проверка созданных объектов
    cout << "Адрес первой квартиры: " << a1.getAddress() << endl;
    cout << "Площадь первой квартиры: " << a1.getArea() << endl;
    cout << "Количество комнат в первой квартире: " << a1.getRooms() << endl;

    cout << "Адрес второй квартиры: " << a2.getAddress() << endl;
    cout << "Площадь второй квартиры: " << a2.getArea() << endl;
    cout << "Количество комнат во второй квартире: " << a2.getRooms() << endl;

    cout << "Адрес третьей квартиры: " << a3.getAddress() << endl;
    cout << "Площадь третьей квартиры: " << a3.getArea() << endl;
    cout << "Количество комнат в третьей квартире: " << a3.getRooms() << endl;

    return 0;
}
