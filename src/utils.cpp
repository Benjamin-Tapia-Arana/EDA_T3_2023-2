#include <iostream>
#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include <string>
using namespace std;

namespace utils{

int getPrecedence(char c) {
    if      (c == '+' || c == '-')  return 2;
    else if (c == '*' || c == '/')  return 3;
    else if (c == '^')              return 4;
    else if (c == '(')              return 1;
    else return 0;
}

void infixToPostfix(std::string *expression) {
    
    std::string infixExpression = *expression;
    stack::Stack* s = new stack::Stack();
    std::string postfixExpression = "";

    for (int i = 0; i < infixExpression.length(); i++) {
        if (infixExpression[i] == '(') {
            node::Node* newNode = new node::Node(infixExpression[i]);
            s->push(newNode);
        }
        else if (infixExpression[i] == ')') {
            while (s->top() != nullptr && s->top()->getData() != '(') {
                postfixExpression += s->top()->getData();
                s->pop();
            }
            delete s->top();
            s->pop();
        }
        else if (infixExpression[i] == '+' || infixExpression[i] == '-' || infixExpression[i] == '*' || infixExpression[i] == '/') {
            int precedence = getPrecedence(infixExpression[i]);
            while (s->top() != nullptr && getPrecedence(s->top()->getData()) >= precedence) {
                postfixExpression += s->top()->getData();
                delete s->top();
                s->pop();
            }
            node::Node* newNode = new node::Node(infixExpression[i]);
            s->push(newNode);
        }
        else postfixExpression += infixExpression[i];
    }

    while (s->top() != nullptr) {
        postfixExpression += s->top()->getData();
        delete s->top();
        s->pop();
    }
    delete s;

    *expression = postfixExpression;
}

}
