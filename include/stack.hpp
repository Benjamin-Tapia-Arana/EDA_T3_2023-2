// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#ifndef STACK_HPP_
#define STACK_HPP_

#include "node.hpp"
#include <string>

namespace stack{
    
class StringStack{
    private:
        node::StringNode* head;
    public:
        StringStack();
        void push(std::string val);
        void push(node::StringNode* node);
        void pop();
        node::StringNode* top();
        bool isEmpty();
        void clear();
        virtual ~StringStack();
};

class FloatStack{
    private:
        node::FloatNode* head;
    public:
        FloatStack();
        void push(long double val);
        void push(node::FloatNode* node);
        void pop();
        node::FloatNode* top();
        bool isEmpty();
        void clear();
        virtual ~FloatStack();
};

}

#endif
