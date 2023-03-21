#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>

#include "binarySearchTree.h"
#include "redBlackTree.h"

using namespace std;

const std::string deleteNodes_dir = "data/deleteNodes.csv";
const std::string testrandom_dir = "data/testrandom.csv";
const std::string testBad_dir = "data/testBad.csv";

//function for parsing the .csv files.
std::vector<int> readCSV(std::string directory){
    std::ifstream infile(directory.c_str());
    std::vector<int> vec;

    if(!infile) {
        std::cerr << "Error: Could not open file " << directory << std::endl;
        return std::vector<int>();
    }

    size_t lineNo = 0;
    std::string line;
    while(std::getline(infile, line)){
        //std::cout << line << std::endl;
        
        if(lineNo > 0){
            std::stringstream ss(line);
            std::string token;

            std::getline(ss, token, ',');
            
            int current = std::stoi(token);
            vec.push_back(current);
        }

        ++lineNo;
    }

    return vec;
}

void testBST(std::string insertions_dir, std::string deletions_dir) {
    Trees::BinarySearchTree<int> test;
    
    for(int i : readCSV(insertions_dir)){
        test.insert(i);
    }

    std::cout << "BST (" << insertions_dir << ") (height: " << test.getHeight() << ") before deletion: ";
    test.inorderPrintTree();
    std::cout << std::endl;

    for(int i : readCSV(deletions_dir)) {
        test.remove(i);
    }

    std::cout << "BST (" << insertions_dir << ") (height: " << test.getHeight() << ") after deletion: ";
    test.inorderPrintTree();
    std::cout << std::endl;
}

void testRBT(std::string insertions_dir, std::string deletions_dir) {
    Trees::RedBlackTree<int> test;
    
    for(int i : readCSV(insertions_dir)){
        test.insert(i);
    }

    std::cout << "RBT (" << insertions_dir << ") (height: " << test.getHeight() << ") before deletion: ";
    test.inorderPrintTree();
    std::cout << std::endl;

    for(int i : readCSV(deletions_dir)) {
        test.remove(i);
    }

    std::cout << "RBT (" << insertions_dir << ") (height: " << test.getHeight() << ") after deletion: ";
    test.inorderPrintTree();
    std::cout << std::endl;
}

int main(){ 
    
    testBST(testBad_dir, deleteNodes_dir);
    testBST(testrandom_dir, deleteNodes_dir);

    testRBT(testBad_dir, deleteNodes_dir);
    testRBT(testrandom_dir, deleteNodes_dir);

    return 0;
}














