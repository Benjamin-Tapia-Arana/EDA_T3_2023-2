#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include <string>
#include <algorithm>
#include <cctype>

namespace utils{

int getPrecedence(std::string c) {
    if      (c == "+" || c == "-")  return 2;
    else if (c == "*" || c == "/")  return 3;
    else if (c == "^")              return 4;
    else if (c == "(")              return 1;
    else return 0;
}

void infixToPostfix(std::string *expression) {
    
    std::string infixExpression = *expression;
    stack::StringStack* s = new stack::StringStack();
    std::string postfixExpression = "";

    for (int i = 0; i < infixExpression.length(); i++) {
        if (infixExpression[i] == '(') {
            node::StringNode* newNode = new node::StringNode(std::string(1, infixExpression[i]));
            s->push(newNode);
        }
        else if (infixExpression[i] == ')') {
            while (s->top() != nullptr && s->top()->getData() != "(") {
                postfixExpression += s->top()->getData();
                s->pop();
            }
            delete s->top();
            s->pop();
        }
        else if (infixExpression[i] == '+' || infixExpression[i] == '-' || infixExpression[i] == '*' || infixExpression[i] == '/' || infixExpression[i] == '^') {
            int precedence = getPrecedence(std::string(1, infixExpression[i]));
            while (s->top() != nullptr && getPrecedence(s->top()->getData()) >= precedence) {
                postfixExpression += s->top()->getData();
                delete s->top();
                s->pop();
            }
            node::StringNode* newNode = new node::StringNode(std::string(1 ,infixExpression[i]));
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

int strToInt(std::string number) {
    int integer = std::stoi(number);
    return integer;
}

void removeEmptySpaces(std::string *input) {
    input->erase(
        std::remove_if(input->begin(),
        input->end(),
        [](char c) {return std::isspace(c);}),
        input->end());
}

}
