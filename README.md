# EE599-HW5
Lei Ding

Github: https://github.com/lding-code/EE599-HW5.git

Q1 
Implemented as depth() method of BST class. A helper method getMaxLevel() is implemented to find the max depth recursively. The depth() method is simply a container that returns the return value of the getMaxLevel() method.
Tested using Gtest with different cases explained in the comment section of each test.

Runtim = O(n) as the depth of each leaf needs to be found and that involves traversing over all elements.


Q2 a (recursive)
Implemented as toInorderRec() method of BST class. A helper method getOrderedVecRec() is implemented to traverse recursively. The toInorderRec() method is besically a container that returns the return value of the helper method.
Tested using GTest with different cases explained in the comment section of each test.

Runtime = O(n) as every element is visited for at least once.

Q2 b (non-recursive)
Implemented as toInorder() method of BST class.
Tested using GTest with different cases explained in the comment section of each test.

Runtime = O(n) as every element is visited for at lease once.