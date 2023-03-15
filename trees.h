#ifndef ABSTRACT_TREE_H
#define ABSTRACT_TREE_H

#include <concepts>
#include <iostream>

template <std::totally_ordered T>
class Tree {
public:
    virtual ~Tree() {}

    //member functions to be implemented by each tree
    virtual bool contains(const T& value) const = 0;
    virtual void insert(const T& value) = 0;
    virtual void remove(const T& value) = 0;
    virtual void print() const = 0;
    virtual void clear() = 0;
};

template <std::totally_ordered T>
struct Node {
    T value;
    Node* left;
    Node* right;
    Node(const T& v) : value(v), left(nullptr), right(nullptr) {}
};

template <std::totally_ordered T>
class BinarySearchTree : public Tree<T> {
private:
    Node<T> *root;

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree();

    bool contains(const T& value) const {
        
        return false;
    }

    void insert(const T& value){

    }

    void remove(const T& value){

    }

    void print() const {

    }

    void clear(){

    }

};

template <std::totally_ordered T>
class RedBlackTree : public Tree<T> {
private:
    Node<T> *root;

public:
    RedBlackTree() : root(nullptr) {}
    ~RedBlackTree();

    bool contains(const T& value) const {
        
        return false;
    }

    void insert(const T& value){

    }

    void remove(const T& value){

    }

    void print() const {

    }

    void clear(){

    }

};

#endif
