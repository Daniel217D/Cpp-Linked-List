#include <iostream>

#include "libraries/List.h"

using namespace std;

void task(List *&list);

int main() {
    List *list;
    read_list_console(list);

    task(list);

    delete list;
    return 0;
}

// Самая длинная упорядоченная подпоследовательность
// Если несколько, то с наибольшей суммой
// Если несколько, то первую
// Удалить последний элемент

void task(List *&list) {
    list->print();
    bool is_up = true;
    int sum = 0, max_sum = 0, length = 0, max_length = 0;
    List *remove_item = nullptr, *current = list;

    while (current) {
        length++;
        sum += current->getValue();

        //Если последовательность прервалась
        if (current->getNext() == nullptr ||
            (is_up && current->getNext()->getValue() <= current->getValue()) ||
            (!is_up && current->getNext()->getValue() >= current->getValue())) {

            //Если новый максимум
            if (length > max_length || (length == max_length && sum > max_sum)) {
                max_length = length;
                max_sum = sum;
                remove_item = current;
            }

            is_up = !is_up;
            sum = current->getValue();
            length = 1;
        }

        current = current->getNext();
    }

    list->remove(remove_item);
    list->print();

    delete current;
}