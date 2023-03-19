#include "tests.h"


namespace Tests {

    std::array<int, 5> sorted = {1, 2, 3, 4, 5};
    std::array<int, 5> rsorted = {5, 4, 3, 2, 1};
    std::array<int, 7> perfect = {4, 2, 6, 1, 3, 5, 7};

    void insert_sorted(Trees::BinarySearchTree<int>& bst) {
        for(int i : sorted)
            bst.insert(i);
    }

    void insert_rsorted(Trees::BinarySearchTree<int>& bst) {
        for(int i : rsorted)
            bst.insert(i);
    }
    
    void insert_perfect(Trees::BinarySearchTree<int>& bst) {
        for(int i : perfect)
            bst.insert(i);
    }

    void binarySearchTree_runAllTests() {
        const std::string testName = "binarySearchTree_runAllTests() ";
        binarySearchTree_containsTest();
        binarySearchTree_insertTest();
        binarySearchTree_deleteTest();
        binarySearchTree_heightTest();
        binarySearchTree_printTest();

        std::cout << " *** " << testName << "complete! *** " << std::endl;
    }

    void binarySearchTree_containsTest() {
        const std::string testName = "binarySearchTree_containsTest() ";
        Trees::BinarySearchTree<int> test;
        
        //test that contains() functions as expected when the tree is empty:
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

    void binarySearchTree_insertTest(){
        const std::string testName = "binarySearchTree_insertTest() ";
        Trees::BinarySearchTree<int> test;

        //insert all elements in the sorted array, and test to make sure they're in the tree:
        insert_sorted(test);
        for(int i : sorted)
            assert((void("contains sorted elements"), test.contains(i)));
        
        std::cout << testName << "passed `inserted/contains sorted elements` checks!" << std::endl;
        test.clearTree();

        //insert all elements in the reverse sorted array, then test if they are in the tree:
        insert_rsorted(test);
        for(int i : rsorted)
            assert((void("contains rsorted elements"), test.contains(i)));
        
        std::cout << testName << "passed `inserted/contains rsorted elements` checks!" << std::endl;
        test.clearTree();
        
        //insert all elements in the array to make a perfect tree, then test if they're in the tree:
        insert_perfect(test);
        for(int i : perfect)
            assert((void("contains perfect elements"), test.contains(i)));

        std::cout << testName << "passed `inserted/contains perfect elements` checks!" << std::endl;
        test.clearTree();

        std::cout << testName << "passed ALL CHECKS!" << std::endl;
    }

    void binarySearchTree_deleteTest() {
        const std::string testName = "binarySearchTree_deleteTest() ";
        Trees::BinarySearchTree<int> test;

        //test that deletion works on all of the sorted elements
        insert_sorted(test);
        for(int i : sorted) {
            assert((void("contains sorted element prior to deletion"), test.contains(i)));
            test.remove(i);
            assert((void("nolonger contains sorted element after deletion"), !test.contains(i)));
        }

        std::cout << testName << "passed `insert/delete sorted elements` checks!" << std::endl;
        test.clearTree();
        
        //test that deletion works on all rsorted elements
        insert_rsorted(test);
        for(int i : rsorted) {
            assert((void("contains rsorted element prior to deletion"), test.contains(i)));
            test.remove(i);
            assert((void("nolonger contains rsorted element after deletion"), !test.contains(i)));
        }

        std::cout << testName << "passed `insert/delete rsorted elements` checks!" << std::endl;
        test.clearTree();
        
        //test that deletion works on all perfect elements
        insert_perfect(test);
        for(int i : perfect) {
            assert((void("contains perfect element prior to deletion"), test.contains(i)));
            test.remove(i);
            assert((void("nolonger contains perfect element after deletion"), !test.contains(i)));
        }

        std::cout << testName << "passed `insert/delete perfect elements` checks!" << std::endl;
        test.clearTree();

        std::cout << testName << "passed ALL CHECKS!" << std::endl;
    }

    void binarySearchTree_heightTest() {
        const std::string testName = "binarySearchTree_heightTest() ";
        Trees::BinarySearchTree<int> test;

        //test that the height is correct on sorted elements
        insert_sorted(test);
//        std::cout << "SORTED HEIGHT: " << test.getHeight() << std::endl;
        assert((void("height on sorted elements"), (test.getHeight() == 5)));
        std::cout << testName << "passed `height check on sorted elements` check!" << std::endl;
        test.clearTree();

        //test that the height is correct on reverse sorted elements
        insert_rsorted(test);
//        std::cout << "RSORTED HEIGHT: " << test.getHeight() << std::endl;
        assert((void("height on rsorted elements"), (test.getHeight() == 5)));
        std::cout << testName << "passed `height check on rsorted elements` check!" << std::endl;
        test.clearTree();

        //test that the height is correct on perfect elements
        insert_perfect(test);
//        std::cout << "PERFECT HEIGHT: " << test.getHeight() << std::endl;
        assert((void("height on perfect elements"), (test.getHeight() == 3)));
        std::cout << testName << "passed `height check on perfect elements` check!" << std::endl;
        test.clearTree();

        std::cout << testName << "passed ALL CHECKS!" << std::endl;
    }

    void binarySearchTree_printTest() {
        const std::string testName = "binarySearchTree_printTest() ";
        Trees::BinarySearchTree<int> test;

        //print out the tree where sorted elements were inserted
        std::cout << testName << "sorted print test:" << std::endl;
        insert_sorted(test);
        test.printTree();
        test.clearTree();

        //print out the tree where rsorted elements were inserted
        std::cout << testName << "rsorted print test:" << std::endl;
        insert_rsorted(test);
        test.printTree();
        test.clearTree();

        //print out the tree where "perfect" elements were inserted (should be a perfect BST)
        std::cout << testName << "perfect print test:" << std::endl;
        insert_perfect(test);
        test.printTree();
        test.clearTree();

        std::cout << testName << "ALL CHECKS complete." << std::endl;
    }
}










