// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#ifndef STACK_HPP_
#define STACK_HPP_

#include "node.hpp"

namespace stack{
    
class Stack{
    private:
        node::Node* head;
    public:
        Stack();
        void push(char val);
        void push(node::Node* node);
        void pop();
        node::Node* top();
        bool isEmpty();
        void clear();
        virtual ~Stack();
};

}

#endif