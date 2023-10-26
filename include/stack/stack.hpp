// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#ifndef STACK_HPP_
#define STACK_HPP_

#include "node/node.hpp"

namespace stack{
    
class Stack{
    private:
        node::Node* head;
    public:
        Stack();
        void push(int posX, int posY);
        void push(node::Node* node);
        void pop();
        node::Node* top();
        bool isEmpty();
        void clear();
        virtual ~Stack();
};

}

#endif