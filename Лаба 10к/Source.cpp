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
        cout << "Данные успешно сохранены в файле." << endl;
    }
    else {
        cout << "Ошибка открытия файла для сохранения данных." << endl;
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
        cout << "Данные успешно прочитаны из файла." << endl;
    }
    else {
        cout << "Ошибка открытия файла для чтения данных." << endl;
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
    cout << "Записи удалены из заданного интервала." << endl;
}

void doubleMoneyValues(vector<Money>& moneyList, const Money& value) {
    for (Money& money : moneyList) {
        money = money + (value.rubles + value.kopeks / 100.0);
    }
    cout << "Значения денежных сумм увеличены в два раза." << endl;
}

void addMoneyEntries(vector<Money>& moneyList, int K) {
    for (int i = 0; i < K; ++i) {
        long r;
        int k;
        cout << "Введите сумму (рубли и копейки через пробел): ";
        cin >> r >> k;
        moneyList.insert(moneyList.begin(), Money(r, k));
    }
    cout << "Записи успешно добавлены в начало файла." << endl;
}

void displayMoneyList(const vector<Money>& moneyList) {
    cout << "Содержимое файла:" << endl;
    for (const Money& money : moneyList) {
        money.display();
        cout << endl;
    }
}

int main() {
    setlocale(0, "");
    vector<Money> moneyList;

    while (true) {
        cout << "МЕНЮ:" << endl;
        cout << "1. Ввести данные и сохранить их в файл" << endl;
        cout << "2. Прочитать данные из файла" << endl;
        cout << "3. Удалить записи из интервала" << endl;
        cout << "4. Увеличить значения в два раза" << endl;
        cout << "5. Добавить записи в начало файла" << endl;
        cout << "6. Вывести содержимое файла" << endl;
        cout << "0. Выход" << endl;

        int choice;
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
        case 1: {
            long r;
            int k;
            cout << "Введите сумму (рубли и копейки через пробел): ";
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
            cout << "Введите интервал для удаления (k1 и k2): " << endl;
            cin >> k1.rubles >> k1.kopeks >> k2.rubles >> k2.kopeks;
            deleteMoneyInRange(moneyList, k1, k2);
            saveMoneyToFile(moneyList, "money_data.dat");
            break;
        }
        case 4: {
            Money value;
            cout << "Введите значение, на которое увеличить денежные суммы (рубли и копейки через пробел): ";
            cin >> value.rubles >> value.kopeks;
            doubleMoneyValues(moneyList, value);
            saveMoneyToFile(moneyList, "money_data.dat");
            break;
        }
        case 5: {
            int K;
            cout << "Введите количество записей, которые нужно добавить в начало файла: ";
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
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
            break;
        }

        cout << endl;
    }

    return 0;
}
