// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#include "node.hpp" 
#include <iostream>

namespace node {

StringNode::StringNode() {
    data = '\0';
    ptrNext = nullptr;
}
StringNode::StringNode(std::string val) {
    data = val;
    ptrNext = nullptr;
}
StringNode::StringNode(std::string val, StringNode* next) {
    data = val;
    ptrNext = next;
}
void StringNode::setData(std::string val) {data = val;}
void StringNode::setNext(StringNode* next) {ptrNext = next;}
std::string StringNode::getData() {return data;}
StringNode* StringNode::getNext() {return ptrNext;}
void StringNode::print() {std::cout << "( " << data << " )";}
StringNode::~StringNode() {};


FloatNode::FloatNode() {
    data = '\0';
    ptrNext = nullptr;
}
FloatNode::FloatNode(long double val) {
    data = val;
    ptrNext = nullptr;
}
FloatNode::FloatNode(long double val, FloatNode* next) {
    data = val;
    ptrNext = next;
}
void FloatNode::setData(long double val) {data = val;}
void FloatNode::setNext(FloatNode* next) {ptrNext = next;}
long double FloatNode::getData() {return data;}
FloatNode* FloatNode::getNext() {return ptrNext;}
void FloatNode::print() {std::cout << "( " << data << " )";}
FloatNode::~FloatNode() {};

}