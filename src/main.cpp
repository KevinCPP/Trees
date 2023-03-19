#include <bits/stdc++.h>

#include "binarySearchTree.h"

using namespace std;

int main(){
    Trees::BinarySearchTree<int> t;
    
    //test insertion:
    t.insert(10);
    t.insert(20);
    t.insert(5);
    t.insert(1);
    t.insert(15);

    t.printTree();

    return 0;
}
