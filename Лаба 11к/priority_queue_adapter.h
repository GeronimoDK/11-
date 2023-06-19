#pragma once
#pragma once
#include <iostream>
#include <queue>
using namespace std;

template<typename T>
class PriorityQueueAdapter {
private:
    priority_queue<T> elements;

public:
    void addElement(const T& element);
    void removeElement(const T& element);
    void printElements();
    void taskExecution();
};

template<typename T>
void PriorityQueueAdapter<T>::addElement(const T& element) {
    elements.push(element);
}

template<typename T>
void PriorityQueueAdapter<T>::removeElement(const T& element) {
    priority_queue<T> temp;

    while (!elements.empty()) {
        if (elements.top() != element) {
            temp.push(elements.top());
        }
        elements.pop();
    }

    while (!temp.empty()) {
        elements.push(temp.top());
        temp.pop();
    }
}

template<typename T>
void PriorityQueueAdapter<T>::printElements() {
    cout << "�������� ������� � ������������: ";
    priority_queue<T> temp = elements;

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;
}

template<typename T>
void PriorityQueueAdapter<T>::taskExecution() {
    if (elements.empty()) {
        cout << "������� � ������������ �����." << endl;
        return;
    }

    // ������� 3: ����� ������� � �������� ������ � �������� ��� �� �������� ������� � �������
    T key = T(42);  // ������ ������������� ������������ ��� ����������������� ����
    size_t position = 2;
    priority_queue<T> temp;

    while (!elements.empty()) {
        if (elements.top() == key) {
            temp.push(key);
        }
        temp.push(elements.top());
        elements.pop();
    }

    elements = temp;

    cout << "������� " << key << " �������� �� ������� " << position << endl;

    // ������� 4: ����� ������� � �������� ������ � ������� ��� �� �������
    T keyToRemove = T(24);
    temp = priority_queue<T>();

    while (!elements.empty()) {
        if (elements.top() != keyToRemove) {
            temp.push(elements.top());
        }
        elements.pop();
    }

    elements = temp;

    cout << "������� " << keyToRemove << " ������ �� �������." << endl;

    // ������� 5: ����� ������� ����� ������������ � ����������� ���������� �������
    T maxElement = elements.top();
    T minElement = elements.top();

    while (!elements.empty()) {
        maxElement = max(maxElement, elements.top());
        minElement = min(minElement, elements.top());
        elements.pop();
    }

    T diff = maxElement - minElement;
    cout << "������� ����� ������������ � ����������� ����������: " << diff << endl;

    temp = priority_queue<T>();

    while (!elements.empty()) {
        temp.push(elements.top() - diff);
        elements.pop();
    }

    elements = temp;

    cout << "�������� ������� ����� ��������� �������: ";
    temp = elements;

    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }

    cout << endl;
}
