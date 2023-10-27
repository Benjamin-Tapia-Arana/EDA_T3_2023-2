#ifndef UTILS_HPP_
#define UTILS_HPP_

#include "stack.hpp"
#include "node.hpp"
#include <string>

namespace utils{

void infixToPostfix(std::string *infixExpression);

int strToInt(std::string character);

void removeEmptySpaces(std::string *input);

}

#endif
