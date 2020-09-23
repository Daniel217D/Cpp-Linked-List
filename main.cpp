#include <iostream>

#include "libraries/List.h"
#include "libraries/tasks.h"

using std::cout;

int main() {
    List *list = new List;
    bool success = list->read_file("files/input1.txt");

    if (success) {
        cout << "Список:\n";
        list->print();

        success = task(list);

        cout << "Результат:\n";
        list->print();
        if(!success) {
            cout << "Подпоследовательность не найдена";
        }
    } else {
        cout << "Файл не открыт\n";
    }

    delete list;
    return 0;
}