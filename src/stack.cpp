// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#include "linkedLists/stack.hpp"
#include "node/node.hpp"

namespace stack{

Stack::Stack(){head = nullptr;}

void Stack::push(int posX, int posY){
    node::Node* node = new node::Node(posX, posY);
    push(node);
}

void Stack::push(node::Node* node){
    if (isEmpty()) {head = node;}
    else {
        node->setNext(head);
        head = node;
    }
}

void Stack::pop(){
    if (!isEmpty()) {
        node::Node* ptr = head;
        head = head->getNext();
        delete ptr;
    }
}

node::Node* Stack::top(){return head;}

bool Stack::isEmpty(){return head == nullptr;}

void Stack::clear(){while(!isEmpty()){pop();}}

Stack::~Stack(){clear();}

}