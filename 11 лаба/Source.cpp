#include <iostream>
#include <fstream>

using namespace std;

struct Node { // структура узла списка
    int data;
    Node* next; // указатель на следующий узел
    Node* prev; // указатель на предыдущий узел
};

Node* createList(int n) { // функция для создания двунаправленного списка
    Node* head = nullptr;
    Node* prev = nullptr;
    for (int i = 0; i < n; i++) { // цикл для создания заданного количества узлов
        Node* newNode = new Node;
        cout << "Введите значение для элемента списка: ";
        cin >> newNode->data;
        newNode->next = nullptr;
        newNode->prev = prev;
        if (prev != nullptr) { // если это не первый элемент списка
            prev->next = newNode;
        }
        else { // если это первый элемент списка
            head = newNode;
        }
        prev = newNode;
    }
    return head;
}

void printList(Node* head) { // функция для печати списка
    if (head == nullptr) { // если список пустой
        cout << "Список пустой" << endl;
        return;
    }
    Node* curr = head;
    cout << "Элементы списка: " << endl;
    while (curr != nullptr) { // цикл для перебора всех узлов списка
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void deleteNode(Node* head, int pos) { // функция для удаления элемента из списка
    Node* curr = head;
    for (int i = 1; i < pos; i++) { // цикл для поиска узла с заданным номером
        if (curr == nullptr || curr->next == nullptr) { // если достигли конца списка
            cout << "В списке нет элемента с таким номером" << endl;
            return;
        }
        curr = curr->next;
    }
    Node* delNode = curr->next; // удаляемый узел
    curr->next = delNode->next; // удаляем узел из списка
    if (delNode->next != nullptr) {
        delNode->next->prev = curr;
    }
    delete delNode; // освобождаем память
    cout << "Элемент после элемента с номером " << pos << " удален" << endl;
}

void addNodes(Node*& head, int k) { // функция для добавления элементов в начало списка
    for (int i = 0; i < k; i++) { // цикл для добавления заданного количества элементов
        Node* newNode = new Node;
        cout << "Введите значение для добавляемого элемента списка: ";
        cin >> newNode->data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }
    cout << "Добавлено " << k << " элементов в начало списка" << endl;
}

void writeToFile(Node* head) { // функция для записи списка в файл
    ofstream fout("list.txt");
    Node* curr = head;
    while (curr != nullptr) { // цикл для перебора всех узлов списка
        fout << curr->data << " ";
        curr = curr->next;
    }
    fout.close();
    cout << "Список записан в файл" << endl;
}

void destroyList(Node*& head) { // функция для уничтожения списка
    Node* curr = head;
    while (curr != nullptr) { // цикл для удаления каждого узла
        Node* delNode = curr;
        curr = curr->next;
        delete delNode;
    }
    head = nullptr;
    cout << "Список уничтожен" << endl;
}

Node* readFromFile() { // функция для восстановления списка из файла
    ifstream fin("list.txt");
    if (!fin.is_open()) { // если файл не удалось открыть
        cout << "Не удалось открыть файл" << endl;
        return nullptr;
    }
    Node* head = nullptr;
    Node* prev = nullptr;
    int value;
    while (fin >> value) { // цикл считывания значений из файла
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
    cout << "Список восстановлен из файла" << endl;
    return head;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int n, pos, k;
    cout << "Введите количество элементов списка: ";
    cin >> n;
    Node* list = createList(n);
    printList(list);
    cout << "Введите номер элемента, после которого нужно удалить элемент из списка: ";
    cin >> pos;
    deleteNode(list, pos);
    printList(list);
    cout << "Введите количество элементов, которые нужно добавить в начало списка: ";
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