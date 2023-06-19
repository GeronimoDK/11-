#pragma once
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class Vector {
private:
    vector<T> elements;

public:
    void addElement(const T& element);
    void removeElement(const T& element);
    void printElements();
    void taskExecution();
};

template<typename T>
void Vector<T>::addElement(const T& element) {
    elements.push_back(element);
}

template<typename T>
void Vector<T>::removeElement(const T& element) {
    elements.erase(remove(elements.begin(), elements.end(), element), elements.end());
}

template<typename T>
void Vector<T>::printElements() {
    cout << "�������� �������: ";
    for (const auto& element : elements) {
        cout << element << " ";
    }
    cout << endl;
}

template<typename T>
void Vector<T>::taskExecution() {
    if (elements.empty()) {
        cout << "������ ����." << endl;
        return;
    }

    // ������� 3: ����� ������� � �������� ������ � �������� ��� �� �������� ������� �������
    T key = T(42);  // ������ ������������� ������������ ��� ����������������� ����
    size_t position = 2;
    auto it = find(elements.begin(), elements.end(), key);
    if (it != elements.end()) {
        elements.insert(elements.begin() + position, *it);
        cout << "������� " << key << " �������� �� ������� " << position << endl;
    }
    else {
        cout << "������� " << key << " �� ������." << endl;
    }

    // ������� 4: ����� ������� � �������� ������ � ������� ��� �� �������
    T keyToRemove = T(24);
    it = find(elements.begin(), elements.end(), keyToRemove);
    if (it != elements.end()) {
        elements.erase(it);
        cout << "������� " << keyToRemove << " ������ �� �������." << endl;
    }
    else {
        cout << "������� " << keyToRemove << " �� ������." << endl;
    }

    // ������� 5: ����� ������� ����� ������������ � ����������� ���������� �������
    auto maxElement = max_element(elements.begin(), elements.end());
    auto minElement = min_element(elements.begin(), elements.end());
    if (maxElement != elements.end() && minElement != elements.end()) {
        T diff = *maxElement - *minElement;
        cout << "������� ����� ������������ � ����������� ����������: " << diff << endl;

        // �������� ������� �� ������� �������� �������
        transform(elements.begin(), elements.end(), elements.begin(),
            [diff](const T& element) { return element - diff; });

        cout << "�������� ������� ����� ��������� �������: ";
        for (const auto& element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }
    else {
        cout << "������ ���� ��� �������� ������ ���� �������." << endl;
    }
}
