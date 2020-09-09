#include <iostream>

using namespace std;

class List {
private:
    int value;
    List *next;
public:
    List(int _value) : value(_value), next(nullptr) {};

    ~List() {
        delete next;
    }

    int getValue() {
        return value;
    };

    List *getNext() {
        return next;
    };

    List *getLast() {
        List *current = this;

        while (current->next) {
            current = current->next;
        };

        return current;
    };

    List *add(int _value) {
        List *list = new List(_value);
        return getLast()->next = list;
    };

    void remove(List *item) {
        List *current = this;

        while (current->next) {
            if (current->next == item) {
                List *next = current->next->next;
                item->next = nullptr;
                delete item;
                current->next = next;
            }
            current = current->next;
        }
    }

    void print() {
        List *current = this;
        cout << "\n" << "Значения элементов; ";
        while (current) {
            cout << current->value << (current->next ? ", " : "\n");
            current = current->next;
        }
    }
};

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

// Самая длинная упорядоченная подпоследовательность
// Если несколько, то с наибольшей суммой
// Если несколько, то первую;
void task(List *&list) {
    list->print();
    bool is_up = true;
    int sum = 0, max_sum = 0, length = 0, max_length = 0;
    List *remove_item = nullptr, *current = list;
    cout << "\n";
    while (current) {
        length++;
        sum += current->getValue();

        if (is_up) {
            if ((current->getNext() == nullptr ||
                 current->getNext()->getValue() <= current->getValue()) &&
                (length > max_length ||
                 (length <= max_length &&
                  sum > max_sum))) {
                max_length = length;
                max_sum = sum;
                remove_item = current;
                is_up = false;
                sum = 0;
                length = 0;
            }
        } else {
            if ((current->getNext() == nullptr ||
                 current->getNext()->getValue() >= current->getValue()) &&
                sum > max_sum) {
                max_sum = sum;
                remove_item = current;
                is_up = true;
                sum = 0;
            }
        }

        current = current->getNext();
    }

    list->remove(remove_item);
    list->print();
}

int main() {
    List *list;
    read_list_console(list);
    task(list);
    delete list;
    return 0;
}