#include <iostream>
#include "calculator.hpp"
#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "tree.hpp"
#include <string>
#include <cmath>

namespace calculator{

long double postfixCalculator(std::string postfixExpression, tree::Tree* t) {
    stack::FloatStack* s = new stack::FloatStack();
    long double result = 0;
    int level = 0;
    for (int i = 0; i < postfixExpression.length(); i += 2) {
        if (postfixExpression[i] == '+' || postfixExpression[i] == '-' || postfixExpression[i] == '*' || postfixExpression[i] == '/' || postfixExpression[i] == '^') {
            
            long double operand2 = s->top()->getData();
            s->pop();
            
            long double operand1 = s->top()->getData();
            s->pop();

            if (postfixExpression[i] == '+') result = operand1 + operand2;
            else if (postfixExpression[i] == '-') result = operand1 - operand2;
            else if (postfixExpression[i] == '*') result = operand1 * operand2;
            else if (postfixExpression[i] == '/') result = operand1 / operand2;
            else if (postfixExpression[i] == '^') result = std::pow(operand1, operand2);
            std::cout << operand1 << ' ' << postfixExpression[i] << ' ' << operand2 << " = " << result << std::endl;
            node::FloatNode* newNode = new node::FloatNode(result);
            s->push(newNode);

            level++;
            if (level == 1) {
                node::TreeNode* topNode = new node::TreeNode(level, std::to_string(operand2));
                t->insertFirst(topNode);
            }
            node::TreeNode* bottomNode = new node::TreeNode(level + 1, std::string(1, postfixExpression[i]));
            node::TreeNode* topNode = new node::TreeNode(level, std::to_string(operand1));
            t->insertFirst(topNode);
            t->insertLast(bottomNode);
        }
        else {
            int j = i;
            while (postfixExpression[j + 1] != ' ') j++;
            node::FloatNode* newNode = new node::FloatNode(utils::strToInt(postfixExpression.substr(i, j - i + 1)));
            s->push(newNode);
            i = j;
        }
    }
    result = s->top()->getData();
    delete s;
    return result;
}

}