#include "List.h"
#include <stdexcept>

template<typename T>
List<T>::List() : head(nullptr) {}

template<typename T>
List<T>::~List() { clear(); }

template<typename T>
void List<T>::push_back(const T& value) {
    Node<T>* newNode = new Node<T>{ value, nullptr };
    if (!head) {
        head = newNode;
    }
    else {
        Node<T>* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
    }
}

template<typename T>
void List<T>::push_front(const T& value) {
    Node<T>* newNode = new Node<T>{ value, head };
    head = newNode;
}

template<typename T>
void List<T>::pop_front() {
    if (!head) return;
    Node<T>* tmp = head;
    head = head->next;
    delete tmp;
}

template<typename T>
bool List<T>::isEmpty() const {
    return head == nullptr;
}

template<typename T>
T List<T>::front() const {
    if (!head) throw std::runtime_error("List is empty");
    return head->data;
}

template<typename T>
void List<T>::clear() {
    while (!isEmpty()) pop_front();
}

// Explicit instantiation for int
template class List<int>;
