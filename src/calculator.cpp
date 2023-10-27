#include <iostream>
#include "calculator.hpp"
#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include <string>
#include <cmath>

namespace calculator{

long double postfixCalculator(std::string postfixExpression) {
    stack::FloatStack* s = new stack::FloatStack();
    long double result = 0;
    for (int i = 0; i < postfixExpression.length(); i += 2) {
        if (postfixExpression[i] == '+' || postfixExpression[i] == '-' || postfixExpression[i] == '*' || postfixExpression[i] == '/' || postfixExpression[i] == '^') {
            
            long double operand2 = s->top()->getData();
            // std::cout << operand2 << ' ';
            s->pop();
            
            long double operand1 = s->top()->getData();
            // std::cout << operand1 << std::endl;
            s->pop();

            if (postfixExpression[i] == '+') result = operand1 + operand2;
            else if (postfixExpression[i] == '-') result = operand1 - operand2;
            else if (postfixExpression[i] == '*') result = operand1 * operand2;
            else if (postfixExpression[i] == '/') result = operand1 / operand2;
            else if (postfixExpression[i] == '^') result = std::pow(operand1, operand2);
            std::cout << operand1 << ' ' << postfixExpression[i] << ' ' << operand2 << " = " << result << std::endl;
            node::FloatNode* newNode = new node::FloatNode(result);
            s->push(newNode);
        }
        else {
            int j = i;
            while (postfixExpression[j + 1] != ' ') j++;
            node::FloatNode* newNode = new node::FloatNode(utils::strToInt(postfixExpression.substr(i, j - i + 1)));
            // std::cout << newNode->getData() << std::endl << std::endl;
            s->push(newNode);
            i = j;
        }
    }
    result = s->top()->getData();
    delete s;
    return result;
}

}