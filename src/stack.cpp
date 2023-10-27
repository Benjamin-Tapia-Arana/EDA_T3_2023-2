// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#include "stack.hpp"
#include "node.hpp"
#include <string>

namespace stack{

StringStack::StringStack(){head = nullptr;}
void StringStack::push(std::string val){
    node::StringNode* node = new node::StringNode(val);
    push(node);
}
void StringStack::push(node::StringNode* node){
    if (isEmpty()) {head = node;}
    else {
        node->setNext(head);
        head = node;
    }
}
void StringStack::pop(){
    if (!isEmpty()) {
        node::StringNode* ptr = head;
        head = head->getNext();
        // delete ptr;
    }
}
node::StringNode* StringStack::top(){return head;}
bool StringStack::isEmpty(){return head == nullptr;}
void StringStack::clear(){while(!isEmpty()){pop();}}
StringStack::~StringStack(){clear();}


FloatStack::FloatStack(){head = nullptr;}
void FloatStack::push(long double val){
    node::FloatNode* node = new node::FloatNode(val);
    push(node);
}
void FloatStack::push(node::FloatNode* node){
    if (isEmpty()) {head = node;}
    else {
        node->setNext(head);
        head = node;
    }
}
void FloatStack::pop(){
    if (!isEmpty()) {
        node::FloatNode* ptr = head;
        head = head->getNext();
        // delete ptr;
    }
}
node::FloatNode* FloatStack::top(){return head;}
bool FloatStack::isEmpty(){return head == nullptr;}
void FloatStack::clear(){while(!isEmpty()){pop();}}
FloatStack::~FloatStack(){clear();}


}