#include <iostream>
#include "List.h"

using namespace std;

// === ÑÒÅÊ ===

void push(Node*& top, datatype value) {
    Node* temp = new Node{ value, top, nullptr, };
    top = temp;
}

void pop(Node*& top) {
    if (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    else {
        cout << "Stack is empty\n";
    }
}

void showStack(Node* top) {
    cout << "Stack: ";
    while (top) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

// === ×ÅÐÃÀ ===

void enqueue(Node*& front, Node*& rear, datatype value) {
    Node* temp = new Node{ value, nullptr, nullptr };
    if (!rear) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

void dequeue(Node*& front, Node*& rear) {
    if (front) {
        Node* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
    }
    else {
        cout << "Queue is empty\n";
    }
}

void showQueue(Node* front) {
    cout << "Queue: ";
    while (front) {
        cout << front->data << " ";
        front = front->next;
    }
    cout << endl;
}

// === ÄÂÎÇÂ’ßÇÍÈÉ ÑÏÈÑÎÊ ===

void add_begin(Node*& head, datatype value) {
    Node* temp = new Node{ value, head, nullptr };
    if (head) head->previous = temp;
    head = temp;
}

void add_end(Node*& head, datatype value) {
    Node* temp = new Node{ value, nullptr, nullptr };
    if (!head) {
        head = temp;
    }
    else {
        Node* current = head;
        while (current->next) current = current->next;
        current->next = temp;
        temp->previous = current;
    }
}

void del_begin(Node*& head) {
    if (head) {
        Node* temp = head;
        head = head->next;
        if (head) head->previous = nullptr;
        delete temp;
    }
}

void del_end(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* current = head;
    while (current->next) current = current->next;
    current->previous->next = nullptr;
    delete current;
}

Node* search(Node* head, datatype key) {
    while (head) {
        if (head->data == key) return head;
        head = head->next;
    }
    return nullptr;
}

void add_mid(Node*& head, datatype key, datatype value) {
    Node* found = search(head, key);
    if (found) {
        Node* temp = new Node{ value, found->next, found };
        if (found->next) found->next->previous = temp;
        found->next = temp;
    }
    else {
        cout << "Element not found\n";
    }
}

void del_mid(Node*& head, datatype key) {
    Node* found = search(head, key);
    if (found) {
        if (found->previous) found->previous->next = found->next;
        else head = found->next;
        if (found->next) found->next->previous = found->previous;
        delete found;
    }
    else {
        cout << "Element not found\n";
    }
}

void showList(Node* head) {
    cout << "List: ";
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
    