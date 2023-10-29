#include "interactiveIO.hpp"
#include "calculator.hpp"
#include "utils.hpp"
#include "dictionary.hpp"
#include "tree.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

namespace interact {

int interactiveIO() {

    struct dictionary::Dictionary dict;
    tree::Tree* t = new tree::Tree();
    long double zero = 0;
    dict.data["ans"] = zero;
    bool showVars = false;
    bool showTree = false;
    
    while(true) {

        std::string instructions;

        system("clear");
        std::cout << "\n - Type an expression or a variable assignment to begin" << std::endl;
        std::cout << " - Type 'vars' to see all assigned variables" << std::endl;
        std::cout << " - Type 'exit' to exit the program" << std::endl;
        std::cout << " - Type 'tree' to see the decision tree of the postfix expression" << std::endl;
        std::cout << " - Type 'vars + tree' to see both\n" << std::endl;
        std::cout << "\n  ans = " << dict.data["ans"] << std::endl;

        if (showVars) {
            bool empty = true;
            std::cout << "\n  Variables:" << std::endl;
            for (const auto& pair : dict.data) {
                if (pair.first != "ans") {
                    std::cout << "   " << pair.first << " = " << pair.second << std::endl;
                    empty = false;
                }
            }
            if (empty) std::cout << "  None" << std::endl;
            showVars = false; 
        }
        if (showTree) {
            std::cout << "\n  Tree:" << std::endl;
            t->print();
            showTree = false;
        }

        std::cout << "\n|-> ";
        std::getline(std::cin, instructions);
        size_t variableAssign = instructions.find("=");
        if (instructions == "exit") {
            system("clear");
            return 0;
        }
        else if (instructions == "vars") showVars = true;
        else if (instructions == "tree") showTree = true;
        else if (instructions == "vars + tree") {
            showVars = true;
            showTree = true;
        }
        else if (variableAssign != std::string::npos) {
            if (instructions != "ans" && instructions != "vars" && instructions != "exit") {
                utils::removeEmptySpaces(&instructions);
                size_t variableAssign = instructions.find("=");
                std::string variableName = instructions.substr(0, variableAssign);
                int intExpression = utils::strToInt(instructions.substr(variableAssign + 1, instructions.length() - variableAssign - 1));
                long double floatExpression = intExpression;
                dict.data[variableName] = floatExpression;
            }
        }
        else {
            t->clear();
            utils::removeEmptySpaces(&instructions);
            utils::infixToPostfix(&instructions);
            std::cout << instructions << std::endl;
            utils::varToVal(&instructions, dict);
            long double solvedExpression = calculator::postfixCalculator(instructions, t);
            std::cout << solvedExpression << std::endl;
            dict.data["ans"] = solvedExpression;
        }
    }
}

}