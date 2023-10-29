#ifndef CALCULATOR_HPP_
#define CALCULATOR_HPP_

#include "calculator.hpp"
#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include "tree.hpp"
#include <iostream>
#include <string>


namespace calculator{

long double postfixCalculator(std::string postfixExpression, tree::Tree* t);

}

#endif
