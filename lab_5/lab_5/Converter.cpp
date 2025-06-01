#include "Converter.h"
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

// Перевірка на оператор
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Пріоритет оператора
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// З інфіксної у постфіксну 
string InfixToPostfix(const string& infix) {
    stack<char> opStack;
    string postfix;

    for (char c : infix) {
        if (isspace(c)) continue;

        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {                                   // виймаємо оператори зі стеку до відкриваючої дужки.
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            if (!opStack.empty()) opStack.pop(); 
        }
        else if (isOperator(c)) {                             //  поки стек не порожній і верхній оператор має вищий або рівний пріоритет — переносимо в результат.
            while (!opStack.empty() &&
                (precedence(opStack.top()) > precedence(c) ||
                    (precedence(opStack.top()) == precedence(c) && c != '^')) &&
                opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}

// З інфіксної у префіксну
string InfixToPrefix(const string& infix) {
    string reversedInfix = infix;
    reverse(reversedInfix.begin(), reversedInfix.end());

    for (char& c : reversedInfix) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }

    string postfix = InfixToPostfix(reversedInfix);
    reverse(postfix.begin(), postfix.end());

    return postfix;
}

// З постфіксної у інфіксну
string PostfixToInfix(const string& postfix) {
    stack<string> s;

    for (char c : postfix) {
        if (isspace(c)) continue;

        if (isalnum(c)) {
            s.push(string(1, c));
        }
        else if (isOperator(c)) {
            if (s.size() < 2) return "Error";
            string b = s.top(); s.pop();
            string a = s.top(); s.pop();
            string expr = "(" + a + c + b + ")";
            s.push(expr);
        }
    }

    return s.empty() ? "Error" : s.top();
}

// З префіксної у інфіксну
string PrefixToInfix(const string& prefix) {
    stack<string> s;

    for (int i = prefix.length() - 1; i >= 0; --i) {
        char c = prefix[i];
        if (isspace(c)) continue;

        if (isalnum(c)) {
            s.push(string(1, c));
        }
        else if (isOperator(c)) {
            if (s.size() < 2) return "Error";
            string a = s.top(); s.pop();
            string b = s.top(); s.pop();
            string expr = "(" + a + c + b + ")";
            s.push(expr);
        }
    }

    return s.empty() ? "Error" : s.top();
}

int EvaluatePostfix(const string& postfix) {
    stack<int> s;

    for (char c : postfix) {
        if (isspace(c)) continue;

        if (isdigit(c)) {
            s.push(c - '0');
        }
        else if (isOperator(c)) {
            if (s.size() < 2) return 0;
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            switch (c) {
            case '+': s.push(a + b); break;
            case '-': s.push(a - b); break;
            case '*': s.push(a * b); break;
            case '/': s.push(a / b); break;
            case '^': s.push(pow(a, b)); break;
            }
        }
    }

    return s.empty() ? 0 : s.top();
}

int EvaluatePrefix(const string& prefix) {
    stack<int> s;

    for (int i = prefix.length() - 1; i >= 0; --i) {
        char c = prefix[i];
        if (isspace(c)) continue;

        if (isdigit(c)) {
            s.push(c - '0');
        }
        else if (isOperator(c)) {
            if (s.size() < 2) return 0;
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
            switch (c) {
            case '+': s.push(a + b); break;
            case '-': s.push(a - b); break;
            case '*': s.push(a * b); break;
            case '/': s.push(a / b); break;
            case '^': s.push(pow(a, b)); break;
            }
        }
    }

    return s.empty() ? 0 : s.top();
}
