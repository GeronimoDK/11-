#include "container.h"
#include "money.h"
#include "vector.h"
#include "priority_queue_adapter.h"

int main() {
    setlocale(0, "");
    // ѕример использовани€ класса Container
    Container container;
    container.addElement(1.23);
    container.addElement(2.71);
    container.addElement(3.14);
    container.addElement(4.56);
    container.printElements();
    container.taskExecution();
    container.printElements();

    // ѕример использовани€ пользовательского типа Money
    Money money(100, 50);
    cout << money << endl;

    // ѕример использовани€ параметризированного класса Vector
    Vector<int> intVector;
    intVector.addElement(10);
    intVector.addElement(20);
    intVector.addElement(30);
    intVector.addElement(40);
    intVector.printElements();
    intVector.taskExecution();
    intVector.printElements();

    // ѕример использовани€ адаптера контейнера - очереди с приоритетами
    PriorityQueueAdapter<int> priorityQueue;
    priorityQueue.addElement(30);
    priorityQueue.addElement(10);
    priorityQueue.addElement(20);
    priorityQueue.addElement(40);
    priorityQueue.printElements();
    priorityQueue.taskExecution();
    priorityQueue.printElements();

    return 0;
}
