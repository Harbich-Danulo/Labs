#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

typedef string datatype;

struct Node {
    datatype data;
    Node* next;
    Node* previous;
};

// Стек
void push(Node*& top, datatype value);
void pop(Node*& top);
void showStack(Node* top);

// Черга
void enqueue(Node*& front, Node*& rear, datatype value);
void dequeue(Node*& front, Node*& rear);
void showQueue(Node* front);

// Двозв’язний список
void add_begin(Node*& head, datatype value);
void add_end(Node*& head, datatype value);
void del_begin(Node*& head);
void del_end(Node*& head);
Node* search(Node* head, datatype key);
void add_mid(Node*& head, datatype key, datatype value);
void del_mid(Node*& head, datatype key);
void showList(Node* head);

#endif
