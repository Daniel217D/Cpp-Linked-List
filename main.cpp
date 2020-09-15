#include "libraries/utils.h"
#include "libraries/List.h"
#include "libraries/tasks.h"

int main() {
    srand(time(NULL));


    List *list = nullptr;
    bool is_exit = false;
    short menu_item;

    while (!is_exit) {
        print_menu();
        menu_item = get_var<short>("Выберите пункт меню: ", 1, 3);

        switch(menu_item) {
            case 1: {
                fill_list_console(list);
                break;
            }
            case 2: {
                fill_list_random(list);
                break;
            }
            case 3: {
                fill_list_file(list);
                break;
            }
        }

        list->print();
        task(list);
        list->print();

        delete list;
        is_exit = ask_exit();
    }


    delete list;
    return 0;
}