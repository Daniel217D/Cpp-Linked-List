#include "List.h"
#include "utils.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::ifstream;

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

void fill_list_console(List *&list) {
    int length = get_var<int>("Количество чисел "), num = get_var<int>("Числа: ");

    list = new List(num);
    for (int i = 0; i < length - 1; ++i) {
        cin >> num;
        list->add(num);
    }
}

void fill_list_random(List *&list) {
    int length;

    length = get_var<int>("Количество чисел: ");

    list = new List(mrand(-50, 50));
    for (int i = 0; i < length - 1; ++i) {
        list->add(mrand(-50, 50));
    }
}

void fill_list_file(List *&list) {
    int value;
    ifstream file("files/input1.txt");

    file >> value;
    list = new List(value);

    while (file >> value) {
        list->add(value);
    }

    file.close();
}