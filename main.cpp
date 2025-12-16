#include <iostream>
#include "ProcessList.h"
using namespace std;

int main() {
    ProcessList myList;
    cout << "Список создан." << endl << endl;

    PCB p1(3, "ProcessA", RUNNING, 100);
    PCB p2(1, "ProcessB", WAITING, 50);
    PCB p3(5, "ProcessC", STOPPED, 200);
    PCB p4(2, "ProcessD", RUNNING, 120);
    PCB p5(4, "ProcessE", WAITING, 80);

    myList.insert(p1);
    myList.insert(p2);
    myList.insert(p3);
    myList.insert(p4);
    myList.insert(p5);

    cout << "Список после вставки:" << endl;
    myList.printList();

    cout << "Удаляем процесс с ID=5:" << endl;
    if (myList.remove(5)) {
        cout << "Успешно удалено." << endl;
    } else {
        cout << "Не удалось удалить." << endl;
    }

    cout << "Удаляем процесс с ID=1:" << endl;
    if (myList.remove(1)) {
        cout << "Успешно удалено." << endl;
    } else {
        cout << "Не удалось удалить." << endl;
    }

    cout << endl << "Список после удаления:" << endl;
    myList.printList();

    cout << "Попытка вставки существующего ID=3:" << endl;
    PCB p6(3, "ProcessF", RUNNING, 300);
    if (!myList.insert(p6)) {
        cout << "Вставка не удалась (повтор ID)." << endl;
    }

    cout << "Попытка удаления несуществующего ID=99:" << endl;
    if (!myList.remove(99)) {
        cout << "Удаление не удалось (ID не найден)." << endl;
    }

    cout << endl << "Финальный список:" << endl;
    myList.printList();

    return 0;
}