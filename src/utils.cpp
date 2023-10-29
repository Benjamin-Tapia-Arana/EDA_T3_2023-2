#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "dictionary.hpp"
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
    bool sameNumber = false;
    int counter = 0;

    for (int i = 0; i < infixExpression.length(); i++) {
        if (infixExpression[i] == '(') {
            node::StringNode* newNode = new node::StringNode(std::string(1, infixExpression[i]));
            s->push(newNode);
            sameNumber = false;
        }
        else if (infixExpression[i] == ')') {
            while (s->top() != nullptr && s->top()->getData() != "(") {
                postfixExpression += s->top()->getData() + ' ';
                s->pop();
                counter += 2;
            }
            delete s->top();
            s->pop();
            sameNumber = false;
        }
        else if (infixExpression[i] == '+' || infixExpression[i] == '-' || infixExpression[i] == '*' || infixExpression[i] == '/' || infixExpression[i] == '^') {
            int precedence = getPrecedence(std::string(1, infixExpression[i]));
            while (s->top() != nullptr && getPrecedence(s->top()->getData()) >= precedence) {
                postfixExpression += s->top()->getData() + ' ';
                delete s->top();
                s->pop();
                counter += 2;
            }
            node::StringNode* newNode = new node::StringNode(std::string(1 ,infixExpression[i]));
            s->push(newNode);
            sameNumber = false;
        }
        else {
            if (!sameNumber) {
                postfixExpression += std::string(1, infixExpression[i]) + ' ';
                counter += 2;
            }
            else {
                postfixExpression[counter - 1] = std::string(1, infixExpression[i])[0];
                postfixExpression += ' ';
                counter += 1;
            }
            sameNumber = true;
        }
    }
    while (s->top() != nullptr) {
        postfixExpression += s->top()->getData() + ' ';
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

void varToVal(std::string *postfixExpression, struct dictionary::Dictionary dict) {
    std::string expression = *postfixExpression;
    std::string variable; 
    long double value;
    for (int i = 0; i < expression.length(); i += 2) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '^') continue;
        else {
            for (const auto& pair : dict.data) {
                variable = pair.first;
                std::cout << "Val: " << variable << std::endl;
                value = pair.second;
                std::cout << "Var: " << value << std::endl;
                std::cout << "Act: " << expression.substr(i, variable.length()) << std::endl << std::endl;
                if (expression.substr(i, variable.length()) == variable) expression.replace(i, variable.length(), std::to_string(value));
                while (expression[i + 1] != ' ') i++;
            }
        }
    }
    *postfixExpression = expression;
}

}
