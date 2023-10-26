// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#include "node.hpp" 
#include <iostream>

namespace node{

Node::Node() {
    data = '\0';
    ptrNext = nullptr;
}

Node::Node(char val) {
    data = val;
    ptrNext = nullptr;
}

Node::Node(char val, Node* next) {
    data = val;
    ptrNext = next;
}

void Node::setData(char val) {data = val;}

void Node::setNext(Node* next) {ptrNext = next;}

char Node::getData() {return data;}

Node* Node::getNext() {return ptrNext;}

void Node::print() {std::cout << '( ' << data << ' )';}

Node::~Node() {};

}