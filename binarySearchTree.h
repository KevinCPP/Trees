#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "trees.h"

namespace Trees {
    //binary search tree
    template <std::totally_ordered T>
    class BinarySearchTree : public Tree<T> {
    private:
        Node<T> *root;
        
        Node<T>* insertHelper(Node<T> *r, const T& value) {
            if(r == nullptr)
                return new Node<T>(value);
            else if(value < r->value)
                r->left = insertHelper(r->left, value);
            else if(value > r->value)
                r->right = insertHelper(r->right, value);

            return r;
        }

        Node<T>* removeHelper(Node<T> *r, const T& value) {
            while(r->left != nullptr) {
                r = r->left;
            }
            return r;
        }

    public:
        BinarySearchTree() : root(nullptr) {}
        ~BinarySearchTree(){
            clear(root);
        }

        //returns true if the tree contains value
        bool contains(const T& value) const override {
            
            return false;
        }

        //inserts value into the tree
        void insert(const T& value) override {
            root = insertHelper(root, value);
        }

        //removes value from the tree
        void remove(const T& value) override {
            root = removeHelper(root, value);
        }

    };

}


#endif
