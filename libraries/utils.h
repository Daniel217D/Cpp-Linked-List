#pragma once

#include "iostream"

using std::string;
using std::cin;
using std::cout;

void print_menu();

bool ask_exit();

int mrand(int min, int max);

template<typename T>
T get_var(const string &message) {
    bool is_error_input;
    T value;

    do {
        is_error_input = true;
        cout << message;
        cin >> value;

        if (cin.fail()) {
            cout << "Ошибка ввода\n";
            cin.clear();
            cin.ignore(cin.rdbuf()->in_avail(), '\n');
        } else {
            is_error_input = false;
        }
    } while (is_error_input);

    return value;
}

template<typename T>
T get_var(const string &message, T min, T max) {
    T number;

    do {
        number = get_var<T>(message);

        if (number < min || number > max) {
            cout << "Значение должно быть в диапозоне " << min << " - " << max << "\n";
        }

    } while (number < min || number > max);

    return number;
}