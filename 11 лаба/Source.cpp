#include <iostream>
#include <fstream>

using namespace std;

struct Node { // ��������� ���� ������
    int data;
    Node* next; // ��������� �� ��������� ����
    Node* prev; // ��������� �� ���������� ����
};

Node* createList(int n) { // ������� ��� �������� ���������������� ������
    Node* head = nullptr;
    Node* prev = nullptr;
    for (int i = 0; i < n; i++) { // ���� ��� �������� ��������� ���������� �����
        Node* newNode = new Node;
        cout << "������� �������� ��� �������� ������: ";
        cin >> newNode->data;
        newNode->next = nullptr;
        newNode->prev = prev;
        if (prev != nullptr) { // ���� ��� �� ������ ������� ������
            prev->next = newNode;
        }
        else { // ���� ��� ������ ������� ������
            head = newNode;
        }
        prev = newNode;
    }
    return head;
}

void printList(Node* head) { // ������� ��� ������ ������
    if (head == nullptr) { // ���� ������ ������
        cout << "������ ������" << endl;
        return;
    }
    Node* curr = head;
    cout << "�������� ������: " << endl;
    while (curr != nullptr) { // ���� ��� �������� ���� ����� ������
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void deleteNode(Node* head, int pos) { // ������� ��� �������� �������� �� ������
    Node* curr = head;
    for (int i = 1; i < pos; i++) { // ���� ��� ������ ���� � �������� �������
        if (curr == nullptr || curr->next == nullptr) { // ���� �������� ����� ������
            cout << "� ������ ��� �������� � ����� �������" << endl;
            return;
        }
        curr = curr->next;
    }
    Node* delNode = curr->next; // ��������� ����
    curr->next = delNode->next; // ������� ���� �� ������
    if (delNode->next != nullptr) {
        delNode->next->prev = curr;
    }
    delete delNode; // ����������� ������
    cout << "������� ����� �������� � ������� " << pos << " ������" << endl;
}

void addNodes(Node*& head, int k) { // ������� ��� ���������� ��������� � ������ ������
    for (int i = 0; i < k; i++) { // ���� ��� ���������� ��������� ���������� ���������
        Node* newNode = new Node;
        cout << "������� �������� ��� ������������ �������� ������: ";
        cin >> newNode->data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }
    cout << "��������� " << k << " ��������� � ������ ������" << endl;
}

void writeToFile(Node* head) { // ������� ��� ������ ������ � ����
    ofstream fout("list.txt");
    Node* curr = head;
    while (curr != nullptr) { // ���� ��� �������� ���� ����� ������
        fout << curr->data << " ";
        curr = curr->next;
    }
    fout.close();
    cout << "������ ������� � ����" << endl;
}

void destroyList(Node*& head) { // ������� ��� ����������� ������
    Node* curr = head;
    while (curr != nullptr) { // ���� ��� �������� ������� ����
        Node* delNode = curr;
        curr = curr->next;
        delete delNode;
    }
    head = nullptr;
    cout << "������ ���������" << endl;
}

Node* readFromFile() { // ������� ��� �������������� ������ �� �����
    ifstream fin("list.txt");
    if (!fin.is_open()) { // ���� ���� �� ������� �������
        cout << "�� ������� ������� ����" << endl;
        return nullptr;
    }
    Node* head = nullptr;
    Node* prev = nullptr;
    int value;
    while (fin >> value) { // ���� ���������� �������� �� �����
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = prev;
        if (prev != nullptr) {
            prev->next = newNode;
        }
        else {
            head = newNode;
        }
        prev = newNode;
    }
    fin.close();
    cout << "������ ������������ �� �����" << endl;
    return head;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, pos, k;
    cout << "������� ���������� ��������� ������: ";
    cin >> n;
    Node* list = createList(n);
    printList(list);
    cout << "������� ����� ��������, ����� �������� ����� ������� ������� �� ������: ";
    cin >> pos;
    deleteNode(list, pos);
    printList(list);
    cout << "������� ���������� ���������, ������� ����� �������� � ������ ������: ";
    cin >> k;
    addNodes(list, k);
    printList(list);
    writeToFile(list);
    destroyList(list);
    printList(list);
    list = readFromFile();
    printList(list);
    destroyList(list);
    return 0;
}