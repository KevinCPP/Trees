#ifndef ABSTRACT_TREE_H
#define ABSTRACT_TREE_H

#include <concepts>
#include <iostream>
#include <iomanip>

//trees namespace
namespace Trees {
    /*
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
    }; */


    enum COLOR {
        BLACK = 0,
        RED = 1
    };

    template <std::totally_ordered T>
    class Node {
    public:
        T value;
        COLOR color = RED;
      
        Node<T> *left = nullptr;
        Node<T> *right = nullptr;
        Node<T> *parent = nullptr;

        Node(const T& val) : value(val) {}

        //returns a pointer to the node's uncle
        Node<T>* getUncle() {
            if (parent == nullptr || parent->parent == nullptr)
                return nullptr;

            if (parent == parent->parent->left)
                return parent->parent->right;
            else
                return parent->parent->left;
        }

        Node<T>* getSibling() {
            if(parent == nullptr)
                return nullptr;

            if(this == parent->left)
                return parent->right;
            
            return parent->left;
        }

        void moveDown(Node<T>* newParent) {
            if (parent != nullptr) {
                if(this == parent->left)
                    parent->left = newParent;
                else
                    parent->right = newParent;
            }

            newParent->parent = parent;
            parent = newParent;
        }

        bool hasRedChild() {
            bool l = (left != nullptr) && (left->color == RED);
            bool r = (right != nullptr) && (right->color == RED);

            return (l || r);
        }
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
            
            if(root->color)
                std::cout << "\033[1;31m";
            
            std::cout << std::setw(indent) << ' ' << root->value;
            std::cout << "\033[0m" << std::endl;

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
