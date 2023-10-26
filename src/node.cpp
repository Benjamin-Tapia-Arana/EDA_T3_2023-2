// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#include "node/node.hpp" 
#include <iostream>

namespace node{

Node::Node() {
    posX = -1;
    posY = -1;
    ptrNext = nullptr;
}

Node::Node(int valX, int valY) {
    posX = valX;
    posY = valY;
    ptrNext = nullptr;
}

Node::Node(int valX, int valY, Node* next) {
    posX = valX;
    posY = valY;
    ptrNext = next;
}

void Node::setData(int valX, int valY){
    posX = valX;
    posY = valY;
}

void Node::setNext(Node* next){ptrNext = next;}

int Node::getPosX(){return posX;}

int Node::getPosY(){return posY;}

Node* Node::getNext(){return ptrNext;}

void Node::print(){std::cout << '( ' << posX << ' , ' << posY << ' )';}

Node::~Node(){}

}