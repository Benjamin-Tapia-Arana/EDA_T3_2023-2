#include "interactiveIO.hpp"
#include "calculator.hpp"
#include "utils.hpp"
#include "dictionary.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

namespace interact {

int interactiveIO() {

    struct dictionary::Dictionary dict;
    long double zero = 0;
    dict.data["ans"] = zero;
    bool showVars = false;
    
    while(true) {

        std::string instructions;

        system("clear");
        std::cout << "\n - Type an expression or a variable assignment to begin" << std::endl;
        std::cout << " - Type 'vars' to see all assigned variables" << std::endl;
        std::cout << " - Type 'exit' to exit the program" << std::endl;
        std::cout << "\n  ans = " << dict.data["ans"] << std::endl;

        if (showVars) {
            
            std::cout << "\nVariables:\n" << std::endl;
            for (const auto& pair : dict.data) {
                std::cout << "  " << pair.first << " = " << pair.second << std::endl;
            }
            showVars = false; 
        }

        std::cout << "\n|-> ";
        std::cin >> instructions;
        size_t variableAssign = instructions.find("=");
        if (instructions == "exit") {
            system("clear");
            return 0;
        }
        else if (instructions == "vars") {
            showVars = true;
        }
        else if (variableAssign != std::string::npos) {
            if (instructions != "ans" && instructions != "vars" && instructions != "exit") {
                utils::removeEmptySpaces(&instructions);
                std::string variableName = instructions.substr(0, variableAssign);
                int intExpression = utils::strToInt(instructions.substr(variableAssign + 1, instructions.length() - variableAssign - 1));
                long double floatExpression = intExpression;
                dict.data[variableName] = floatExpression;
            }
        }
        else {
            utils::removeEmptySpaces(&instructions);
            utils::infixToPostfix(&instructions);
            std::cout << instructions << std::endl;
            long double solvedExpression = calculator::postfixCalculator(instructions);
            std::cout << solvedExpression << std::endl;
            dict.data["ans"] = solvedExpression;
        }
    }
}

}