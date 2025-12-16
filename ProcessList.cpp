#include "ProcessList.h"
#include <iostream>
using namespace std;

ProcessList::ProcessList() {
    head = nullptr;
}

ProcessList::~ProcessList() {
    while (head != nullptr) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

bool ProcessList::insert(const PCB& newPCB) {
    ListNode* newNode = new ListNode(newPCB);

    if (head == nullptr) {
        head = newNode;
        return true;
    }

    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current != nullptr) {
        if (current->data.processID == newPCB.processID) {
            delete newNode;
            return false; 
        }
        if (current->data.processID > newPCB.processID) {
            break;
        }
        prev = current;
        current = current->next;
    }

    if (prev == nullptr) {
        newNode->next = head;
        head = newNode;
    }
    else {
        newNode->next = current;
        prev->next = newNode;
    }

    return true;
}

bool ProcessList::remove(int pid) {
    if (head == nullptr) return false;

    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current != nullptr) {
        if (current->data.processID == pid) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }

    return false; 
}

void ProcessList::printList() {
    if (head == nullptr) {
        cout << "Список пуст." << endl;
        return;
    }

    ListNode* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->data.processID
             << ", Имя: " << current->data.processName
             << ", Статус: ";

        switch (current->data.processStatus) {
            case RUNNING: cout << "Running"; break;
            case WAITING: cout << "Waiting"; break;
            case STOPPED: cout << "Stopped"; break;
        }

        cout << ", Счетчик: " << current->data.commandCounter << endl;
        current = current->next;
    }
    cout << "------------------------" << endl;
}