#ifndef CONVERTER_H
#define CONVERTER_H

#include <string>
using namespace std;

bool isOperator(char c);
int precedence(char op);

string InfixToPostfix(const string& infix);
string InfixToPrefix(const string& infix);
string PostfixToInfix(const string& postfix);
string PrefixToInfix(const string& prefix);
int EvaluatePostfix(const string& postfix);
int EvaluatePrefix(const string& prefix);

#endif
