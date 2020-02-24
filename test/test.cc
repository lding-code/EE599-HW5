#include "gtest/gtest.h"
#include <string>
#include <iostream>
#include <vector>

#include "src/lib/solution.h"
#include "src/lib/BST.h"

TEST(HelloWorldShould, ReturnHelloWorld) {
    Solution solution;

    std::string actual = solution.HelloWorld();
    std::string expected = "HelloWorld";

    EXPECT_EQ(expected, actual);
}

// Q1 single branch test 1-2-3-4
TEST(DepthShould1, ReturnDepth1) {
    std::vector<int> input = {1, 2, 3, 4};

    BST bst {input};

    std::cout << "is empty? " << bst.isEmpty() << std::endl;

    int actual = bst.depth();
    int expected = 4;

    EXPECT_EQ(expected, actual);
}

// Q1 question example
TEST(DepthShould2, ReturnDepth2) {
    std::vector<int> input = {3, 20, 15, 2, 27};

    BST bst {input};

    int actual = bst.depth();
    int expected = 3;

    EXPECT_EQ(expected, actual);
}

// Q1 empty tree
TEST(DepthShould3, ReturnDepth3) {
    std::vector<int> input = {};

    BST bst {input};

    int actual = bst.depth();
    int expected = 0;

    EXPECT_EQ(expected, actual);
}

// Q1 complicated random number tree
TEST(DepthShould4, ReturnDepth4) {
    std::vector<int> input = {42, 25, 41, 23, 5, 8, 96, 51, 20, 46, 3, 1, 71, 30, 24, 81, 75, 80};

    BST bst {input};

    int actual = bst.depth();
    int expected = 7;

    EXPECT_EQ(expected, actual);
}

// Q2 rec simple 1-2-3-4
TEST(ToInorderRecShould1, ReturnToInorderRec1) {
    std::vector<int> input = {1, 2, 3, 4};

    BST bst {input};

    std::vector<int> actual = bst.toInorderRec();
    std::vector<int> expected = {1, 2, 3, 4};

    EXPECT_EQ(expected, actual);
}

// Q2 rec question example
TEST(ToInorderRecShould2, ReturnToInorderRec2) {
    std::vector<int> input = {3, 20, 15, 2, 27};

    BST bst {input};

    std::vector<int> actual = bst.toInorderRec();
    std::vector<int> expected = {2, 3, 15, 20, 27};

    EXPECT_EQ(expected, actual);
}

// Q2 rec complicated random tree
TEST(ToInorderRecShould3, ReturnToInorderRec3) {
    std::vector<int> input = {42, 25, 41, 23, 5, 8, 96, 51, 20, 46, 3, 1, 71, 30, 24, 81, 75, 80};

    BST bst {input};

    std::vector<int> actual = bst.toInorderRec();
    std::vector<int> expected = {1, 3, 5, 8, 20, 23, 24, 25, 30, 41, 42, 46, 51, 71, 75, 80, 81, 96};

    EXPECT_EQ(expected, actual);
}

// Q2 non recursive simple 1-2-3-4
TEST(ToInorderShould1, ReturnToInorder1) {
    std::vector<int> input = {2, 1, 3, 4};

    BST bst {input};

    std::vector<int> actual = bst.toInorder();
    std::vector<int> expected = {1, 2, 3, 4};

    EXPECT_EQ(expected, actual);
}

// // Q2 non recursive question example
// TEST(ToInorderShould2, ReturnToInorder2) {
//     std::vector<int> input = {3, 20, 15, 2, 27};

//     BST bst {input};

//     std::vector<int> actual = bst.toInorder();
//     std::vector<int> expected = {2, 3, 15, 20, 27};

//     EXPECT_EQ(expected, actual);
// }

// // Q2 non recursive complicated random tree
// TEST(ToInorderShould3, ReturnToInorder3) {
//     std::vector<int> input = {42, 25, 41, 23, 5, 8, 96, 51, 20, 46, 3, 1, 71, 30, 24, 81, 75, 80};

//     BST bst {input};

//     std::vector<int> actual = bst.toInorder();
//     std::vector<int> expected = {1, 3, 5, 8, 20, 23, 24, 25, 30, 41, 42, 46, 51, 71, 75, 80, 81, 96};

//     EXPECT_EQ(expected, actual);
// }