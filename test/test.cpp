#include <iostream>
#include "utils.hpp"
#include "stack.hpp"
#include "node.hpp"
#include <string>

int main() {
    std::string expression = "(a+(b*c-d)/e+(f*g-h)*i)/j-k*7";
    utils::infixToPostfix(&expression);
    std::cout << expression << std::endl;
    return 0;
}
