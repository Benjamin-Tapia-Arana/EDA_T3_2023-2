// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#ifndef NODE_HPP_
#define NODE_HPP_

#include <string>
#include <iostream>

namespace node{

class StringNode{
private:
    std::string data;
    StringNode* ptrNext;
public:
    StringNode();
    StringNode(std::string val);
    StringNode(std::string val, StringNode* next);
    std::string getData();
    StringNode* getNext();
    void setData(std::string val);
    void setNext(StringNode* next);
    void print();
    virtual ~StringNode();
};

class FloatNode{
private:
    long double data;
    FloatNode* ptrNext;
public:
    FloatNode();
    FloatNode(long double val);
    FloatNode(long double val, FloatNode* next);
    long double getData();
    FloatNode* getNext();
    void setData(long double val);
    void setNext(FloatNode* next);
    void print();
    virtual ~FloatNode();
};

}


#endif
