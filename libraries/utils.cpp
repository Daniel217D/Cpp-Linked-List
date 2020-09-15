#include "utils.h"
#include "iostream"

using std::string;
using std::cin;
using std::cout;

void print_menu() {
    cout << "1. Ввод с клавиатуры\n";
    cout << "2. Случайный ввод\n";
    cout << "3. Ввод из файла\n";
}

bool ask_exit() {
    std::string in;

    while (!(in == "Y" || in == "y" || in == "N" || in == "n")) {
        in = get_var<string>("Завершить работу? (Y/N) -> ");
    }

    return in == "Y" || in == "y";
}

int mrand(int min, int max) {
    return rand() % (max - min + 1) + min;
}