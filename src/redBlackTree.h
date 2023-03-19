#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "trees.h"

namespace Trees {
//red black tree
    template <std::totally_ordered T>
    class RedBlackTree : public Tree<T> {
    private:
        Node<T> *root;

    public:
        RedBlackTree() : root(nullptr) {}
        ~RedBlackTree(){
            clear(root);
        }

        //returns true if the tree contains value
        bool contains(const T& value) const override {
            
            return false;
        }

        //inserts value into the tree
        void insert(const T& value) override{
            
        }

        void remove(const T& value) override {

        }
    };
}


#endif
