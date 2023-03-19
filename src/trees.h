#ifndef ABSTRACT_TREE_H
#define ABSTRACT_TREE_H

#include <concepts>
#include <iostream>
#include <iomanip>

//trees namespace
namespace Trees {
    //this will be used as the node object
    template <std::totally_ordered T>
    struct Node {
        T value;
        bool color = false;
        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;
        Node(const T& v) : value(v) {}
        Node(const T& v, bool c) : value(v), color(c) {} 
    }; 

    //abstract class that contains methods required for all tree types to implement
    template <std::totally_ordered T>
    class Tree {
    public:
        //constructor
        virtual ~Tree() {}

        //member functions to be implemented by each tree
        virtual bool contains(const T& value) const = 0;
        virtual void insert(const T& value) = 0;
        virtual void remove(const T& value) = 0;
    protected:
        void print(Node<T>*& root, uint32_t indent = 4) const {
            if(root == nullptr){
                //std::cout << "Tree is empty" << std::endl;
                return;
            }

            if (root->right != nullptr) {
                print(root->right, indent + 4);
            }

            std::cout << std::setw(indent) << ' ' << root->value << std::endl;

            if (root->left != nullptr) {
                print(root->left, indent + 4);
            }
        }

        virtual ptrdiff_t height(Node<T>* root) const {
            //height of an empty tree is -1
            if(root == nullptr)
                return 0;

            //recursively find height of l/r nodes
            ptrdiff_t l = height(root->left);
            ptrdiff_t r = height(root->right);

            //return the maximum height
            return (1 + (l > r ? l : r));
        }

        virtual void clear(Node<T>*& root) {
            //return and do nothing if it's null
            if(root == nullptr)
                return;

            //if it's not null, clear the children
            clear(root->left);
            clear(root->right);

            //finally, delete and set to nullptr
            delete root;
            root = nullptr;
        } 

    };
}

#endif
