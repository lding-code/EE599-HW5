#include <iostream>

#include "src/lib/solution.h"

#include "src/lib/BST.h"

int main(int argc, char* argv[]) {
    Solution solution;
    std::cout << solution.HelloWorld() << std::endl;


    std::vector<int> input = {2, 1, 3, 4};

    BST bst {input};

    std::vector<int> actual = bst.toInorder();

    return EXIT_SUCCESS;
}