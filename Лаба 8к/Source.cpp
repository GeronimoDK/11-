#include <iostream>
#include <string>
#include <list>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(string _name, int _age) : name(_name), age(_age) {}
    virtual ~Person() {}

    string getName() const { return name; }
    int getAge() const { return age; }

    virtual void input() = 0;
    virtual void output() const = 0;
    bool operator==(const Person& other) const {
        return (name == other.name) && (age == other.age);
    }
};

class Abiturient : public Person {
private:
    int score;
    string specialty;

public:
    Abiturient(string _name, int _age, int _score, string _specialty)
        : Person(_name, _age), score(_score), specialty(_specialty) {}

    int getScore() const { return score; }
    string getSpecialty() const { return specialty; }

    void input() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter score: ";
        cin >> score;
        cout << "Enter specialty: ";
        cin >> specialty;
    }

    void output() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Score: " << score << endl;
        cout << "Specialty: " << specialty << endl;
    }
};

class Group {
public:
    list<Abiturient> students;

public:
    void addStudent(const Abiturient& student) {
        students.push_back(student);
    }

    void removeStudent(const Abiturient& student) {
        students.remove(student);
    }

    void printGroup() const {
        for (const auto& student : students) {
            student.output();
            cout << endl;
        }
    }

    int getSize() const {
        return students.size();
    }
};

class Dialog : public Group {
public:
    void processEvents() {
        char command;
        while (true) {
            cout << "Enter command (+/-/s/z/q): ";
            cin >> command;

            if (command == '+') {
                Abiturient student("", 0, 0, "");
                student.input();
                addStudent(student);
            }
            else if (command == '-') {
                Abiturient student("", 0, 0, "");
                student.input();
                removeStudent(student);
            }
            else if (command == 's') {
                printGroup();
            }
            else if (command == 'z') {
                int totalAge = 0;
                for (const auto& student : students) {
                    totalAge += student.getAge();
                }
                float avgAge = static_cast<float>(totalAge) / getSize();
                cout << "Average age: " << avgAge << endl;
            }
            else if (command == 'q') {
                break;
            }
            else {
                cout << "Invalid command. Try again." << endl;
            }
        }
    }
};

int main() {
    Dialog dialog;
    dialog.processEvents();

    return 0;
}
