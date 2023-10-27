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
    for (int i = 0; i < postfixExpression.length(); i++) {
        if (postfixExpression[i] == '+' || postfixExpression[i] == '-' || postfixExpression[i] == '*' || postfixExpression[i] == '/' || postfixExpression[i] == '^') {
            long double op2 = s->top()->getData();
            long double operand2 = s->top()->getData();
            s->pop();
            long double op1= s->top()->getData();
            long double operand1 = s->top()->getData();
            s->pop();
            if (postfixExpression[i] == '+') result = operand1 + operand2;
            else if (postfixExpression[i] == '-') result = operand1 - operand2;
            else if (postfixExpression[i] == '*') result = operand1 * operand2;
            else if (postfixExpression[i] == '/') result = operand1 / operand2;
            else if (postfixExpression[i] == '^') result = std::pow(operand1, operand2);
            std::cout << op1 << ' ' << postfixExpression[i] << ' ' << op2 << " = " << result << std::endl;
            node::FloatNode* newNode = new node::FloatNode(result);
            s->push(newNode);
        }
        else {
            node::FloatNode* newNode = new node::FloatNode(utils::strToInt(std::string(1, postfixExpression[i])));
            s->push(newNode);
        }
    }
    result = s->top()->getData();
    delete s;
    return result;
}

}