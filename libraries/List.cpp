#include"List.h"

#include<iostream>
#include <fstream>

using std::cout;
using std::string;
using std::ifstream;

Node::Node(int _value, Node *_next = nullptr) : value(_value), next(_next) {}

Node::~Node() {
    delete next;
}

Node *Node::get_next() {
    return next;
}

int Node::get_value() {
    return value;
}

List::~List() {
    delete node;
}

Node *List::get_node() {
    return node;
}

bool List::read_file(const string &name) {
    ifstream fin(name);
    bool success = false;
    int num;

    if (fin.is_open()) {
        success = true;

        while (fin >> num) {
            add_to_tail(num);
        }
    }

    fin.close();
    return success;
}

bool List::is_empty() {
    return node == nullptr;
}

void List::add_to_head(int value) {
    node = new Node(value, node);
}

void List::add_to_tail(int value) {
    if (!is_empty()) {
        Node *current = node;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new Node(value);
    } else {
        add_to_head(value);
    }
}

void List::add_after(Node *&after, int value) {
    if (after == nullptr) {
        return;
    }

    if (!is_empty()) {
        Node *current = node;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = new Node(value);
    } else {
        add_to_head(value);
    }
}

void List::remove(Node *&del_el) {
    if (del_el == nullptr) {
        return;
    }

    if (node == del_el) {
        Node *temp = del_el->next;

        if (temp == nullptr) {
            delete node;
            node = nullptr;
        } else {
            del_el->next = nullptr;
            delete del_el;
            node = temp;
        }
    } else {
        Node *current = node;

        while (current->next != del_el) {
            current = current->next;
        }

        if (current != nullptr) {
            Node *temp = del_el->next;
            del_el->next = nullptr;
            delete del_el;
            current->next = temp;
        }
    }
}

void List::print() {
    Node *current = node;

    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }

    cout << "\n";
}