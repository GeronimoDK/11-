#include <iostream>
#include <string>

using namespace std;

class Apartment {
private:
    string address; // ����� ��������
    double area;    // ������� ��������
    int rooms;      // ���������� ������ � ��������

public:
    // ����������� ��� ����������
    Apartment() {
        address = "";
        area = 0.0;
        rooms = 0;
    }

    // ����������� � �����������
    Apartment(string ad, double ar, int r) {
        address = ad;
        area = ar;
        rooms = r;
    }

    // ����������� �����������
    Apartment(const Apartment& ap) {
        address = ap.address;
        area = ap.area;
        rooms = ap.rooms;
    }

    // ����������
    ~Apartment() {}

    // ��������� � ������������
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

    // �������� �������� � ������� ������ �������������
    Apartment a1;   // ������, ��������� � ������� ������������ ��� ����������
    Apartment a2("��. �������, ��� �����������, ��. 13", 25.5, 1); // ������, ��������� � ������� ������������ � �����������
    Apartment a3 = a2;  // ������, ��������� � ������� ������������ �����������

    // �������� ��������� ��������
    cout << "����� ������ ��������: " << a1.getAddress() << endl;
    cout << "������� ������ ��������: " << a1.getArea() << endl;
    cout << "���������� ������ � ������ ��������: " << a1.getRooms() << endl;

    cout << "����� ������ ��������: " << a2.getAddress() << endl;
    cout << "������� ������ ��������: " << a2.getArea() << endl;
    cout << "���������� ������ �� ������ ��������: " << a2.getRooms() << endl;

    cout << "����� ������� ��������: " << a3.getAddress() << endl;
    cout << "������� ������� ��������: " << a3.getArea() << endl;
    cout << "���������� ������ � ������� ��������: " << a3.getRooms() << endl;

    return 0;
}
