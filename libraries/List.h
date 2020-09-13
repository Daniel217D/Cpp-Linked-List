#pragma once

class List {
private:
    int value;
    List *next;
public:
    List(int _value) ;

    ~List();

    int getValue();

    List *getNext();

    List *getLast();

    List *add(int _value);

    void remove(List *item);

    void print();
};

void read_list_console(List *&list);

void task(List *&list);