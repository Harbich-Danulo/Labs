#include <iostream>
#include "List.h"

using namespace std;

int main() {
    Node* stackTop = nullptr;
    Node* queueFront = nullptr;
    Node* queueRear = nullptr;
    Node* listHead = nullptr;
    int choice, value, key;

    while (true) {
        cout << "\n1. push (stack)\n2. pop (stack)\n3. enqueue (queue)\n4. dequeue (queue)"
            << "\n5. add_begin (list)\n6. add_end (list)\n7. del_begin (list)\n8. del_end (list)"
            << "\n9. search (list)\n10. add_mid (list)\n11. del_mid (list)\n12. Exit\nSelect: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Value: "; cin >> value;
            push(stackTop, value);
            showStack(stackTop);
            break;
        case 2:
            pop(stackTop);
            showStack(stackTop);
            break;
        case 3:
            cout << "Value: "; cin >> value;
            enqueue(queueFront, queueRear, value);
            showQueue(queueFront);
            break;
        case 4:
            dequeue(queueFront, queueRear);
            showQueue(queueFront);
            break;
        case 5:
            cout << "Value: "; cin >> value;
            add_begin(listHead, value);
            showList(listHead);
            break;
        case 6:
            cout << "Value: "; cin >> value;
            add_end(listHead, value);
            showList(listHead);
            break;
        case 7:
            del_begin(listHead);
            showList(listHead);
            break;
        case 8:
            del_end(listHead);
            showList(listHead);
            break;
        case 9:
            cout << "Key: "; cin >> key;
            if (search(listHead, key)) cout << "Found\n";
            else cout << "Not found\n";
            break;
        case 10:
            cout << "Key (add after): "; cin >> key;
            cout << "Value: "; cin >> value;
            add_mid(listHead, key, value);
            showList(listHead);
            break;
        case 11:
            cout << "Key (delete): "; cin >> key;
            del_mid(listHead, key);
            showList(listHead);
            break;
        case 12:
            return 0;
        }
    }
}
