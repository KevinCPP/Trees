#include <bits/stdc++.h>

#include "binarySearchTree.h"

#define UNIT_TEST


//#ifdef UNIT_TEST
#include "../test/tests.h"
void unitTests() {
//    Tests::binarySearchTree_printTest();
//    Tests::binarySearchTree_runAllTests();

//    Tests::redBlackTree_printTest();
    Tests::redBlackTree_runAllTests();
    Tests::binarySearchTree_runAllTests();
}


using namespace std;

int main(){
    
    Trees::RedBlackTree<int> t;

    unitTests();
    return 0;



//    Trees::BinarySearchTree<int> t;
    
    //test insertion:
//    t.insert(10);
//    t.insert(20);
//    t.insert(5);
//    t.insert(1);
//    t.insert(15);

//    t.printTree();
    return 0;
}
