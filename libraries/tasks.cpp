#include "tasks.h"
#include "List.h"
#include <iostream>

using namespace std;

// Самая длинная упорядоченная подпоследовательность
// Если несколько, то с наибольшей суммой
// Если несколько, то первую
// Удалить последний элемент найденной последовательности
bool task(List *&list) {
    bool is_up = true, result;
    int sum = 0, max_sum = 0, length = 0, max_length = 0;
    Node *remove_item = nullptr, *current = list->get_node(), *current_prev = nullptr;

    while (current) {
        length++;
        sum += current->get_value();

        //Если последовательность прервалась
        if (current->get_next() == nullptr || (is_up && current->get_next()->get_value() <= current->get_value()) ||
            (!is_up && current->get_next()->get_value() >= current->get_value())) {

            //Если новый максимум
            if (length > 1 && (length > max_length || (length == max_length && sum > max_sum))) {
                max_length = length;
                max_sum = sum;
                remove_item = current_prev;
            }

            is_up = !is_up;
            //Если следующий элемент равен текущему, то текущий можно не учитывать в последовательности
            if (!current->get_next() || current->get_next()->get_value() == current->get_value()) {
                sum = 0;
                length = 0;
            } else {
                sum = current->get_value();
                length = 1;
            }
        }

        current_prev = current;
        current = current->get_next();
    }

    result = remove_item != nullptr;

    List::remove_next(remove_item);

    return result;
}