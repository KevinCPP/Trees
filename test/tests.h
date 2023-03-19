#ifndef TESTS_H
#define TESTS_H

#include <bits/stdc++.h>
#include "../src/trees.h"
#include "../src/redBlackTree.h"
#include "../src/binarySearchTree.h"

namespace Tests {
    //run all tests
    void runAllTests();

    //run all tests for specific class
    void binarySearchTree_runAllTests();
    void redBlackTree_runAllTests();

    //run specific test for binary search tree
    void binarySearchTree_containsTest();
    void binarySearchTree_insertTest();
    void binarySearchTree_deleteTest();
    void binarySearchTree_heightTest();
    void binarySearchTree_printTest();

    //run specific test for red black tree
    void redBlackTree_containsTest();
    void redBlackTree_insertTest();
    void redBlackTree_deleteTest();
    void redBlackTree_heightTest();
    void redBlackTree_printTest();
}

#endif
