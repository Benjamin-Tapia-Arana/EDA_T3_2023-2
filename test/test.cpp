#include <iostream>
#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "calculator.hpp"
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string expression = "( ( 4 + ( 5 * 2 - 1 ) / 5 + ( 6 * 7 - 4 ) * 2 ) / 4 - 6 * 7 ) ^ 2";
    utils::removeEmptySpaces(&expression);
    utils::infixToPostfix(&expression);
    std::cout << expression << std::endl;
    float solvedExpression = calculator::postfixCalculator(expression);
    std::cout << solvedExpression << std::endl;
    
    return 0;
}
