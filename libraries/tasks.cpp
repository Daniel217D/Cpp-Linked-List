#include "tasks.h"
#include "List.h"
#include <iostream>

using namespace std;

// Самая длинная упорядоченная подпоследовательность
// Если несколько, то с наибольшей суммой
// Если несколько, то первую
// Удалить последний элемент найденной последовательности
void task(List *&list) {
    bool is_up = true;
    int sum = 0, max_sum = 0, length = 0, max_length = 0;
    List *remove_item = nullptr, *current = list;

    while (current) {
        length++;
        sum += current->getValue();

        //Если последовательность прервалась
        if (current->getNext() == nullptr || (is_up && current->getNext()->getValue() <= current->getValue()) ||
            (!is_up && current->getNext()->getValue() >= current->getValue())) {

            //Если новый максимум
            if (length > max_length || (length == max_length && sum > max_sum)) {
                max_length = length;
                max_sum = sum;
                remove_item = current;
            }

            is_up = !is_up;
            //Если следующий элемент равен текущему, то текущий можно не учитывать в последовательности
            if (!current->getNext() || current->getNext()->getValue() == current->getValue()) {
                sum = 0;
                length = 0;
            } else {
                sum = current->getValue();
                length = 1;
            }
        }

        current = current->getNext();
    }

    list->remove(remove_item);
    delete remove_item;
    delete current;
}