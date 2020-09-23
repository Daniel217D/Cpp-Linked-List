#include <iostream>

#include "libraries/List.h"
#include "libraries/tasks.h"

using std::cout;

int main() {
    List *list = new List;
    bool success = list->read_file("files/input1.txt");

    if (success) {
        success = task(list);
        list->print_file("files/output1.txt", !success ? "Подпоследовательность не найдена" : "");
        cout << "Работа успешно завершена";
    } else {
        cout << "Файл не открыт\n";
    }

    delete list;
    return 0;
}