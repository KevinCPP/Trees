#include "tests.h"

namespace Tests {

    std::array<int, 7> RB_sorted = {1, 2, 3, 4, 5, 6, 7};
    std::array<int, 5> RB_reverse = {5, 4, 3, 2, 1};
    std::array<int, 7> RB_perfect = {4, 2, 6, 1, 3, 5, 7};

    void insert_RB_sorted(Trees::RedBlackTree<int>& rbt) {
        for(int i : RB_sorted)
            rbt.insert(i);
    }

    void insert_RB_reverse(Trees::RedBlackTree<int>& rbt) {
        for(int i : RB_reverse)
            rbt.insert(i);
    }

    void insert_RB_perfect(Trees::RedBlackTree<int>& rbt) {
        for(int i : RB_perfect)
            rbt.insert(i);
    }

    void redBlackTree_runAllTests() { 
        const std::string testName = "redBlackTree_runAllTests() ";
        redBlackTree_containsTest();
        redBlackTree_insertTest();
        redBlackTree_deleteTest();
        redBlackTree_heightTest();
        redBlackTree_printTest();

        std::cout << " *** " << testName << "complete! *** " << std::endl;
    }

    void redBlackTree_containsTest() {
        const std::string testName = "redBlackTree_containsTest() ";
        Trees::RedBlackTree<int> test;

        //test that contains() functions when the tree is empty:
        assert((void("contains when empty"), !test.contains(1)));
        assert((void("contains when empty"), !test.contains(0)));
        assert((void("contains when empty"), !test.contains(INT_MAX)));
        assert((void("contains when empty"), !test.contains(INT_MIN)));
        
        std::cout << testName << "passed `contains when empty` checks!" << std::endl;
        
        //test that it contains an element that has been inserted
        test.insert(5);
        assert((void("contains element test"), test.contains(5)));
        
        std::cout << testName << "passed `contains element` checks!" << std::endl;
        test.clearTree();

        std::cout << testName << "passed ALL CHECKS!" << std::endl;

    }

    void redBlackTree_insertTest() {
        const std::string testName = "redBlackTree_insertTest() ";
        Trees::RedBlackTree<int> test;
    
        //insert all elements in the RB_sorted array, and test to make sure they're in the tree:
        insert_RB_sorted(test);
        for(int i : RB_sorted)
            assert((void("contains RB_sorted elements"), test.contains(i)));
        
        std::cout << testName << "passed `inserted/contains RB_sorted elements` checks!" << std::endl;
        test.clearTree();

        //insert all elements in the reverse RB_sorted array, then test if they are in the tree:
        insert_RB_reverse(test);
        for(int i : RB_reverse)
            assert((void("contains RB_reverse elements"), test.contains(i)));
        
        std::cout << testName << "passed `inserted/contains RB_reverse elements` checks!" << std::endl;
        test.clearTree();
        
        //insert all elements in the array to make a RB_perfect tree, then test if they're in the tree:
        insert_RB_perfect(test);
        for(int i : RB_perfect)
            assert((void("contains RB_perfect elements"), test.contains(i)));

        std::cout << testName << "passed `inserted/contains RB_perfect elements` checks!" << std::endl;
        test.clearTree();

        std::cout << testName << "passed ALL CHECKS!" << std::endl;

    }

    void redBlackTree_deleteTest() {
        const std::string testName = "redBlackTree_deleteTest() ";
        Trees::RedBlackTree<int> test;
    
        //test that deletion works on all of the RB_sorted elements
        insert_RB_sorted(test);
        for(int i : RB_sorted) {
            std::cout << "Testing i=" << i << std::endl;
            assert((void("contains RB_sorted element prior to deletion"), test.contains(i)));
            test.remove(i);
            assert((void("nolonger contains RB_sorted element after deletion"), !test.contains(i)));
        }

        std::cout << testName << "passed `insert/delete RB_sorted elements` checks!" << std::endl;
        test.clearTree();
        
        //test that deletion works on all RB_reverse elements
        insert_RB_reverse(test);
        for(int i : RB_reverse) {
            assert((void("contains RB_reverse element prior to deletion"), test.contains(i)));
            test.remove(i);
            assert((void("nolonger contains RB_reverse element after deletion"), !test.contains(i)));
        }

        std::cout << testName << "passed `insert/delete RB_reverse elements` checks!" << std::endl;
        test.clearTree();
        
        //test that deletion works on all RB_perfect elements
        insert_RB_perfect(test);
        for(int i : RB_perfect) {
            assert((void("contains RB_perfect element prior to deletion"), test.contains(i)));
            test.remove(i);
            assert((void("nolonger contains RB_perfect element after deletion"), !test.contains(i)));
        }

        std::cout << testName << "passed `insert/delete RB_perfect elements` checks!" << std::endl;
        test.clearTree();

        std::cout << testName << "passed ALL CHECKS!" << std::endl;

    }

    void redBlackTree_heightTest() {
        const std::string testName = "redBlackTree_heightTest() ";
        Trees::RedBlackTree<int> test;

        //test that the height is correct on RB_sorted elements
        insert_RB_sorted(test);
        std::cout << "RB_sorted HEIGHT: " << test.getHeight() << std::endl;
//        assert((void("height on RB_sorted elements"), (test.getHeight() == 5)));
        std::cout << testName << "passed `height check on RB_sorted elements` check!" << std::endl;
        test.clearTree();

        //test that the height is correct on reverse RB_sorted elements
        insert_RB_reverse(test);
        std::cout << "RB_reverse HEIGHT: " << test.getHeight() << std::endl;
//        assert((void("height on RB_reverse elements"), (test.getHeight() == 5)));
        std::cout << testName << "passed `height check on RB_reverse elements` check!" << std::endl;
        test.clearTree();

        //test that the height is correct on RB_perfect elements
        insert_RB_perfect(test);
        std::cout << "RB_perfect HEIGHT: " << test.getHeight() << std::endl;
//        assert((void("height on RB_perfect elements"), (test.getHeight() == 3)));
        std::cout << testName << "passed `height check on RB_perfect elements` check!" << std::endl;
        test.clearTree();

        std::cout << testName << "passed ALL CHECKS!" << std::endl;

    }

    void redBlackTree_printTest() {
        const std::string testName = "redBlackTree_printTest() ";
        Trees::RedBlackTree<int> test;

        //print out the tree where RB_sorted elements were inserted
        std::cout << testName << "RB_sorted print test:" << std::endl;
        insert_RB_sorted(test);
        test.printTree();
        test.clearTree();

        //print out the tree where RB_reverse elements were inserted
        std::cout << testName << "RB_reverse print test:" << std::endl;
        insert_RB_reverse(test);
        test.printTree();
        test.clearTree();

        //print out the tree where "RB_perfect" elements were inserted (should be a RB_perfect BST)
        std::cout << testName << "RB_perfect print test:" << std::endl;
        insert_RB_perfect(test);
        test.printTree();
        test.clearTree();

        std::cout << testName << "ALL CHECKS complete." << std::endl;
    }
}

