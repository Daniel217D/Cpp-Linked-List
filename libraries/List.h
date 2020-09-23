#pragma once

#include <iostream>

using std::string;

class Node {
private:
    int value;

    Node *next;

    friend class List;

public:
    explicit Node(int _value, Node *_next);

    ~Node();

    Node *get_next();

    int get_value();
};

class List {
private:
    Node *node = nullptr;

public:
    ~List();

    Node *get_node();

    bool read_file(const string &name);

    bool print_file(const string &name, const string &status);

    bool is_empty();

    void add_to_head(int value);

    void add_to_tail(int value);

    void add_after(Node *&after, int value);

    void remove(Node *&del_el);

    static void remove_next(Node *&el);

    void print();
};
