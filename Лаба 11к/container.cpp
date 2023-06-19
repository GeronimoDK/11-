#include "container.h"
#include <algorithm>

using namespace std;

void Container::addElement(double element) {
    elements.push_back(element);
}

void Container::removeElement(double element) {
    elements.remove(element);
}

void Container::printElements() {
    cout << "�������� ����������: ";
    for (const auto& element : elements) {
        cout << element << " ";
    }
    cout << endl;
}

void Container::taskExecution() {
    if (elements.empty()) {
        cout << "��������� ����." << endl;
        return;
    }

    // ������� 3: ����� ������� � �������� ������ � �������� ��� �� �������� ������� ����������
    double key = 3.14;
    double position = 2;
    auto it = find(elements.begin(), elements.end(), key);
    if (it != elements.end()) {
        elements.insert(next(elements.begin(), position), *it);
        cout << "������� " << key << " �������� �� ������� " << position << endl;
    }
    else {
        cout << "������� " << key << " �� ������." << endl;
    }

    // ������� 4: ����� ������� � �������� ������ � ������� ��� �� ����������
    double keyToRemove = 2.71;
    it = find(elements.begin(), elements.end(), keyToRemove);
    if (it != elements.end()) {
        elements.erase(it);
        cout << "������� " << keyToRemove << " ������ �� ����������." << endl;
    }
    else {
        cout << "������� " << keyToRemove << " �� ������." << endl;
    }

    // ������� 5: ����� ������� ����� ������������ � ����������� ���������� ����������
    auto maxElement = max_element(elements.begin(), elements.end());
    auto minElement = min_element(elements.begin(), elements.end());
    if (maxElement != elements.end() && minElement != elements.end()) {
        double diff = *maxElement - *minElement;
        cout << "������� ����� ������������ � ����������� ����������: " << diff << endl;

        // �������� ������� �� ������� �������� ����������
        transform(elements.begin(), elements.end(), elements.begin(),
            [diff](double element) { return element - diff; });

        cout << "�������� ���������� ����� ��������� �������: ";
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
    else {
        cout << "��������� ���� ��� �������� ������ ���� �������." << endl;
    }
}
