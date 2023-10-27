#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "calculator.hpp"
#include "interactiveIO.hpp"
#include <iostream>
#include <string>
#include <list>

int main() {

    interact::interactiveIO();

    // std::string expression = "((4+(5*2-8)/5+(56*7-4)*2)/4-6*7)^2";
    // utils::removeEmptySpaces(&expression);
    // utils::infixToPostfix(&expression);
    // std::cout << expression << std::endl;
    // long double solvedExpression = calculator::postfixCalculator(expression);
    // std::cout << solvedExpression << std::endl;
    return 0;
}
