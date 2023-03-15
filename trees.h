#ifndef ABSTRACT_TREE_H
#define ABSTRACT_TREE_H

#include <concepts>
#include <iostream>

namespace Trees {
    
    namespace {
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
            virtual void print() const = 0;
            virtual void clear() = 0;
        };

        //this will be used as the node object
        template <std::totally_ordered T>
        struct Node {
            T value;
            Node* left;
            Node* right;
            Node(const T& v) : value(v), left(nullptr), right(nullptr) {}
        };
        
    }

    //binary search tree
    template <std::totally_ordered T>
    class BinarySearchTree : public Tree<T> {
    private:
        Node<T> *root;

    public:
        BinarySearchTree() : root(nullptr) {}
        ~BinarySearchTree(){
            clear;
        }

        //returns true if the tree contains value
        bool contains(const T& value) const {
            
            return false;
        }

        //inserts value into the tree
        void insert(const T& value){
            
        }

        //removes value from the tree
        void remove(const T& value){

        }

        //prints the tree
        void print() const {

        }

        //clears the tree
        void clear(){

        }

    };

    //red black tree
    template <std::totally_ordered T>
    class RedBlackTree : public Tree<T> {
    private:
        Node<T> *root;

    public:
        RedBlackTree() : root(nullptr) {}
        ~RedBlackTree(){
            clear();
        }

        //returns true if the tree contains value
        bool contains(const T& value) const {
            
            return false;
        }

        //inserts value into the tree
        void insert(const T& value){

        }

        //removes value from the tree
        void remove(const T& value){

        }

        //prints the tree
        void print() const {

        }

        //clears the tree
        void clear(){

        }
    };

}

#endif
