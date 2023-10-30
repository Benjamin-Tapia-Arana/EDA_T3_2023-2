#include "tree.hpp"
#include "node.hpp"
#include "utils.hpp"
#include <string>

namespace tree{

Tree::Tree(){
    head = nullptr;
    tail = nullptr;
    }

void Tree::insertFirst(node::TreeNode* node){
    if (isEmpty()) {
        head = node;
        tail = node;
        }
    else {
        head->setNext(node);
        node->setPrev(head);
        head = node;
    }
}
void Tree::insertFirst(int lvl, std::string val){
    node::TreeNode* node = new node::TreeNode(lvl, val);
    insertFirst(node);
}

void Tree::insertLast(node::TreeNode* node){
    if (isEmpty()) {
        head = node;
        tail = node;
    }
    else {
        tail->setPrev(node);
        node->setNext(tail);
        tail = node;
    }
}
void Tree::insertLast(int lvl, std::string val){
    node::TreeNode* node = new node::TreeNode(lvl, val);
    insertLast(node);
}

void Tree::pop(){
    if (!isEmpty()) {
        node::TreeNode* ptr = head;
        head = head->getPrev();
        if (head != nullptr) delete ptr;
    }
}

node::TreeNode* Tree::top() {return head;}

void Tree::print(){

    node::TreeNode* ptr;
    int maxLevel = 0;
    int lvl;
    int number;
    std::string data;

    ptr = head;
    while (ptr != nullptr) {
        lvl = ptr->getLevel();
        if (lvl > maxLevel) maxLevel = lvl;
        ptr->setLevel(-1 * lvl);
        ptr = ptr->getPrev();
    }

    ptr = head;
    while (ptr != nullptr) {
        lvl = ptr->getLevel();
        ptr->setLevel(maxLevel + lvl);
        ptr = ptr->getPrev();
    }

    ptr = head;
    while (ptr != nullptr) {
        lvl = ptr->getLevel();
        std::cout << "  ";
        for (int i = 0; i <= lvl; i++) std::cout << "---";
        try {
            number = utils::strToInt(ptr->getData());
            data = std::to_string(number);}
        catch (std::invalid_argument& e) {
            data = ptr->getData();
        }
        std::cout << ' ' << data << std::endl;
        ptr = ptr->getPrev();
    }

    ptr = head;
    while (ptr != nullptr) {
        lvl = ptr->getLevel();
        ptr->setLevel(-1 * lvl);
        ptr = ptr->getPrev();
    }    
}

bool Tree::isEmpty() {return head == nullptr;}

void Tree::clear() {while(!isEmpty()) pop();}

Tree::~Tree() {clear();}

}