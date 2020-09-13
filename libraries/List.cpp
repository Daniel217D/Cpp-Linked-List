#include "List.h"
#include <iostream>

using std::cout;
using std::cin;

List::List(int _value) : value(_value), next(nullptr) {
}

List::~List() {
    delete this->next;
}

int List::getValue() {
    return this->value;
}

List *List::getNext() {
    return this->next;
}

List *List::getLast() {
    auto *current = this;

    while (current->next) {
        current = current->next;
    };

    return current;
}

List *List::add(int _value) {
    auto *list = new List(_value);
    return this->getLast()->next = list;
}

void List::remove(List *item) {
    if (this == item) {
        if (this->next) {
            this->value = this->next->value;
            this->next = this->next->next;
        } else {
            //
        }
    } else {
        auto *current = this;

        while (current) {
            if (current->next == item) {
                List *next;
                if (current->next->next) {
                    next = current->next->next;
                } else {
                    next = nullptr;
                }
                item->next = nullptr;
                delete item;
                current->next = next;
            }
            current = current->next;
        }
    }
}

void List::print() {
    auto *current = this;
    cout << "\n" << "Значения элементов: ";
    while (current) {
        cout << current->value << (current->next ? ", " : "\n");
        current = current->next;
    }
}

void read_list_console(List *&list) {
    int num;
    cout << "Введите числа: ";
    cin >> num;
    list = new List(num);
    for (int i = 1; i < 10; ++i) {
        cin >> num;
        list->add(num);
    }
}