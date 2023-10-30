#ifndef TREE_HPP_
#define TREE_HPP_

#include "node.hpp"
#include <string>

namespace tree{
    
class Tree{
    private:
        node::TreeNode* head;
        node::TreeNode* tail;
    public:
        Tree();
        void insertFirst(int lvl, std::string val);
        void insertFirst(node::TreeNode* node);
        void insertLast(int lvl, std::string val);
        void insertLast(node::TreeNode* node);
        void pop();
        node::TreeNode* top();
        void print();
        bool isEmpty();
        void clear();
        virtual ~Tree();
};

}

#endif
