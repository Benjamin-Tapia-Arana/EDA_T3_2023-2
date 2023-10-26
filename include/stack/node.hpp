// Código del libro Estructuras de Datos y Algoritmos (J. M. Saavedra)

#ifndef NODE_HPP_
#define NODE_HPP_

namespace node{

class Node{
private:
    int posX;
    int posY;
    Node* ptrNext;
public:
    Node();
    Node(int posX, int posY);
    Node(int posX, int posY, Node* next);
    int getPosX();
    int getPosY();
    Node* getNext();
    void setData(int posX, int posY);
    void setNext(Node* next);
    void print();
    virtual ~Node();
};

}

#endif