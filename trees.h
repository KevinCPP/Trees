#ifndef ABSTRACT_TREE_H
#define ABSTRACT_TREE_H

#include <concepts>
#include <iostream>
#include <iomanip>

//trees namespace
namespace Trees {

    //anonymous namespace to contain abstract and node classes, making them inaccessible elsewhere
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
        
        //generic print function for trees
        template <std::totally_ordered T>
        void print(Node<T>* root, size_t level = 0, uint8_t indent = 4){
            if(root == nullptr){
                //std::cout << "Tree is empty" << std::endl;
                return;
            }

            printTree(root->right, level + 1, indent);
            std::cout << std::setw(indent * level) << " ";
            std::cout << root->value << std::endl;
            printTree(root->left, level + 1, indent);
        }

        //generic height calculation function for trees
        template <std::totally_ordered T>
        size_t height(Node<T>* root){
            //height of an empty tree is -1
            if(root == nullptr)
                return -1;

            //recursively find height of l/r nodes
            size_t l = height(root->left);
            size_t r = height(root->right);

            //return the maximum height
            return (1 + (l > r ? l : r));
        }

        //generic clear function for trees
        template <std::totally_ordered T>
        void clear(Node<T>* root){
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
    }

    //binary search tree
    template <std::totally_ordered T>
    class BinarySearchTree : public Tree<T> {
    private:
        Node<T> *root;

    public:
        BinarySearchTree() : root(nullptr) {}
        ~BinarySearchTree(){
            clear();
        }

        //returns true if the tree contains value
        bool contains(const T& value) const {
            
            return false;
        }

        //inserts value into the tree
        void insert(const T& value){
            if(!root) {
                root = new Node<T>;
                root->value = value;
            }
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
