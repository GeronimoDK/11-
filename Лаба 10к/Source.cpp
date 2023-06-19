#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Money {
public:
    long rubles;
    int kopeks;

public:
    Money() : rubles(0), kopeks(0) {}

    Money(long r, int k) : rubles(r), kopeks(k) {}

    void setMoney(long r, int k) {
        rubles = r;
        kopeks = k;
    }

    void display() const {
        cout << rubles << "," << kopeks;
    }

    Money operator+(double value) const {
        Money result;
        double total = rubles + kopeks / 100.0 + value;
        result.rubles = static_cast<long>(total);
        result.kopeks = static_cast<int>((total - result.rubles) * 100);
        return result;
    }

    bool operator>(const Money& other) const {
        return (rubles > other.rubles) || (rubles == other.rubles && kopeks > other.kopeks);
    }

    bool operator<(const Money& other) const {
        return (rubles < other.rubles) || (rubles == other.rubles && kopeks < other.kopeks);
    }

    bool operator==(const Money& other) const {
        return rubles == other.rubles && kopeks == other.kopeks;
    }

    bool operator<=(const Money& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>=(const Money& other) const {
        return (*this > other) || (*this == other);
    }
};

void saveMoneyToFile(const vector<Money>& moneyList, const string& filename) {
    ofstream file(filename, ios::out | ios::binary);
    if (file.is_open()) {
        for (const Money& money : moneyList) {
            file.write(reinterpret_cast<const char*>(&money), sizeof(Money));
        }
        file.close();
        cout << "������ ������� ��������� � �����." << endl;
    }
    else {
        cout << "������ �������� ����� ��� ���������� ������." << endl;
    }
}

vector<Money> readMoneyFromFile(const string& filename) {
    vector<Money> moneyList;
    ifstream file(filename, ios::in | ios::binary);
    if (file.is_open()) {
        Money money;
        while (file.read(reinterpret_cast<char*>(&money), sizeof(Money))) {
            moneyList.push_back(money);
        }
        file.close();
        cout << "������ ������� ��������� �� �����." << endl;
    }
    else {
        cout << "������ �������� ����� ��� ������ ������." << endl;
    }
    return moneyList;
}

void deleteMoneyInRange(vector<Money>& moneyList, const Money& k1, const Money& k2) {
    auto it = moneyList.begin();
    while (it != moneyList.end()) {
        if (*it >= k1 && *it <= k2) {
            it = moneyList.erase(it);
        }
        else {
            ++it;
        }
    }
    cout << "������ ������� �� ��������� ���������." << endl;
}

void doubleMoneyValues(vector<Money>& moneyList, const Money& value) {
    for (Money& money : moneyList) {
        money = money + (value.rubles + value.kopeks / 100.0);
    }
    cout << "�������� �������� ���� ��������� � ��� ����." << endl;
}

void addMoneyEntries(vector<Money>& moneyList, int K) {
    for (int i = 0; i < K; ++i) {
        long r;
        int k;
        cout << "������� ����� (����� � ������� ����� ������): ";
        cin >> r >> k;
        moneyList.insert(moneyList.begin(), Money(r, k));
    }
    cout << "������ ������� ��������� � ������ �����." << endl;
}

void displayMoneyList(const vector<Money>& moneyList) {
    cout << "���������� �����:" << endl;
    for (const Money& money : moneyList) {
        money.display();
        cout << endl;
    }
}

int main() {
    setlocale(0, "");
    vector<Money> moneyList;

    while (true) {
        cout << "����:" << endl;
        cout << "1. ������ ������ � ��������� �� � ����" << endl;
        cout << "2. ��������� ������ �� �����" << endl;
        cout << "3. ������� ������ �� ���������" << endl;
        cout << "4. ��������� �������� � ��� ����" << endl;
        cout << "5. �������� ������ � ������ �����" << endl;
        cout << "6. ������� ���������� �����" << endl;
        cout << "0. �����" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            long r;
            int k;
            cout << "������� ����� (����� � ������� ����� ������): ";
            cin >> r >> k;
            moneyList.push_back(Money(r, k));
            saveMoneyToFile(moneyList, "money_data.dat");
            break;
        }
        case 2: {
            moneyList = readMoneyFromFile("money_data.dat");
            displayMoneyList(moneyList);
            break;
        }
        case 3: {
            Money k1, k2;
            cout << "������� �������� ��� �������� (k1 � k2): " << endl;
            cin >> k1.rubles >> k1.kopeks >> k2.rubles >> k2.kopeks;
            deleteMoneyInRange(moneyList, k1, k2);
            saveMoneyToFile(moneyList, "money_data.dat");
            break;
        }
        case 4: {
            Money value;
            cout << "������� ��������, �� ������� ��������� �������� ����� (����� � ������� ����� ������): ";
            cin >> value.rubles >> value.kopeks;
            doubleMoneyValues(moneyList, value);
            saveMoneyToFile(moneyList, "money_data.dat");
            break;
        }
        case 5: {
            int K;
            cout << "������� ���������� �������, ������� ����� �������� � ������ �����: ";
            cin >> K;
            addMoneyEntries(moneyList, K);
            saveMoneyToFile(moneyList, "money_data.dat");
            break;
        }
        case 6: {
            displayMoneyList(moneyList);
            break;
        }
        default:
            cout << "�������� �����. ���������� ��� ���." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}
