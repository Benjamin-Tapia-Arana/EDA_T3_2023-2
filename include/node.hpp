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

class TreeNode{
private:
    std::string data;
    int level;
    TreeNode* ptrPrev;
    TreeNode* ptrNext;
public:
    TreeNode(int lvl);
    TreeNode(int lvl, std::string val);
    TreeNode(int lvl, std::string val, TreeNode* prev);
    TreeNode(int lvl, std::string val, TreeNode* prev, TreeNode* next);
    std::string getData();
    int getLevel();
    TreeNode* getPrev();
    void setData(std::string val);
    void setPrev(TreeNode* prev);
    void setNext(TreeNode* next);
    void setLevel(int lvl);
    void print();
    virtual ~TreeNode();
};

}

#endif
