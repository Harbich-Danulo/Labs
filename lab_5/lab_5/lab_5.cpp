#include <iostream>
#include "Converter.h"
using namespace std;

int main() {
    int choice;
    string expr;

    do {
        cout << "\nMenu:\n";
        cout << "1. Infix to Postfix\n";
        cout << "2. Infix to Prefix\n";
        cout << "3. Postfix to Infix\n";
        cout << "4. Prefix to Infix\n";
        cout << "5. Evaluate Postfix\n";
        cout << "6. Evaluate Prefix\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice >= 1 && choice <= 6) {
            cout << "Enter expression: ";
            getline(cin, expr);
        }

        switch (choice) {
        case 1: cout << "Postfix: " << InfixToPostfix(expr) << endl; break;
        case 2: cout << "Prefix: " << InfixToPrefix(expr) << endl; break;
        case 3: cout << "Infix: " << PostfixToInfix(expr) << endl; break;
        case 4: cout << "Infix: " << PrefixToInfix(expr) << endl; break;
        case 5: cout << "Result: " << EvaluatePostfix(expr) << endl; break;
        case 6: cout << "Result: " << EvaluatePrefix(expr) << endl; break;
        }

    } while (choice != 0);

    return 0;
}
