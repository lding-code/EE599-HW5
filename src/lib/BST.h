#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class BST {
public:
    BST();

    BST(std::vector<int> initial_values);

    ~BST();

    void push(int key);
    bool find(int key);
    bool erase(int key);
    bool isEmpty();

    std::vector<int> toVector();
    std::vector<int> toInorder();
    std::vector<int> toInorderRec();

    int depth();

private:
    // levelCurr -> current level count
    int getMaxLevel(TreeNode *node, int levelCurr, int levelMax);
    std::vector<int> getOrderedVecRec(TreeNode *node);
    std::vector<int> getOrderedVec(TreeNode *node);

    TreeNode *root_;
    bool empty_;
};