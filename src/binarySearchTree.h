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
            //base case
            if(!r) return r;
            
            
            if (value < r->value) {
                //since it's a BST, go to the left if value is less than this node
                r->left = removeHelper(r->left, value);
            } else if (value > r->value) {
                //since it's a BST, go to the right if value is greater than this node
                r->right = removeHelper(r->right, value);
            } else {
                if(r->left == nullptr) {
                    Node<T>* right = r->right;
                    delete r;
                    r = nullptr;
                    return right;
                } else if (r->right == nullptr) {
                    Node<T>* left = r->left;
                    delete r;
                    r = nullptr;
                    return left;
                } else {
                    Node<T>* minRightNode = minNode(r->right);
                    r->value = minRightNode->value;
                    r->right = removeHelper(r->right, minRightNode->value);
                }
            }

            return r;
        }

        Node<T>* minNode(Node<T> *r) {
            while(r->left != nullptr) {
                r = r->left;
            }
            return r;
        }

    public:
        BinarySearchTree() : root(nullptr) {}
        ~BinarySearchTree(){
            Tree<T>::clear(root);
        }

        //returns true if the tree contains value
        bool contains(const T& value) const override {
            //node that will be used in the iterations
            Node<T> *current = root;

            //while the current node is not null
            while (current) {
                //if the value of the node is the one we are looking for,
                //that means the tree contains it, we can stop here and return true
                if (current->value == value) {
                    return true;

                //if the value is less than the current value, we'll go left since
                //smaller values are always on the left in a binary search tree
                } else if (value < current->value) {
                    current = current->left;
                
                //if the value isn't less or equal, it must be greater, so we can
                //just go to the right, since right = larger values in BST.
                } else {
                    current = current->right;
                }
            }
            
            //if it was not found in that loop, then it isn't in the tree
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

        void printTree() {
            Tree<T>::print(root, 4);
        }

        ptrdiff_t getHeight() const {
            return Tree<T>::height(root);
        }

        void clearTree() {
            Tree<T>::clear(root);
        }
    };

}


#endif
