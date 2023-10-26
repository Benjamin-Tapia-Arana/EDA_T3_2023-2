// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#ifndef NODE_HPP_
#define NODE_HPP_

namespace node{

class Node{
private:
    char data;
    Node* ptrNext;
public:
    Node();
    Node(char val);
    Node(char val, Node* next);
    char getData();
    Node* getNext();
    void setData(char val);
    void setNext(Node* next);
    void print();
    virtual ~Node();
};

}

#endif