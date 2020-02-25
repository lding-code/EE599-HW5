#include "BST.h"

#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <stack>

BST::BST() {
    empty_ = true;
    root_ = new TreeNode(0);
}

BST::BST(std::vector<int> initial_values) {
    empty_ = true;
    root_ = new TreeNode(0);
    for (auto it = initial_values.begin(); it != initial_values.end(); it++) {
        push(*it);
    }
}

BST::~BST() {
    while (empty_ != true) {
        erase((*root_).val);
    }
}

void BST::push(int key) {
    TreeNode *node = root_;
    if (empty_ == true) {
        (*node).val = key;
        empty_ = false;
    }
    else {
        while ((key <= (*node).val && (*node).left != nullptr) || (key > (*node).val && (*node).right != nullptr)) {
            if (key <= (*node).val) {
                node = (*node).left;
            }
            else {
                node = (*node).right;
            }
        }
        TreeNode *newNode = new TreeNode(key);
        if (key <= (*node).val){
            (*node).left = newNode;
        }
        else {
            (*node).right = newNode;
        }
    }
}


bool BST::find(int key) {

    TreeNode *node = root_;
    if (empty_ == false) {
        while (node != nullptr) {
            if (key == (*node).val) {
                return true;
            }
            else if (key < (*node).val) {
                node = (*node).left;
            }
            else {
                node = (*node).right;
            }
        }
        return false;
    }
    else {
        return false;
    }
}


bool BST::erase(int key) {


    if (find(key)) {
        TreeNode *nodeKey = root_;
        TreeNode *nodeParent = nodeKey;
        // find node tih key value
        while (key != (*nodeKey).val) {
            nodeParent = nodeKey;
            if (key < (*nodeKey).val) {
                nodeKey = (*nodeParent).left;
            }
            else {
                nodeKey = (*nodeParent).right;
            }
        }
        // found the node
        // 4 cases:


        // case 1: no children
        if ((*nodeKey).left == nullptr && (*nodeKey).right == nullptr) {
            // case 1.1 the node is root (meaning only root exists in the tree)
            if (nodeKey == root_) {
                empty_ = true;
                return true;
            }
            // case 1.2 the node is other node rather than the root
            else {
                if (key < (*nodeParent).val) {
                    (*nodeParent).left = nullptr;
                }
                else {
                    (*nodeParent).right = nullptr;
                }
                delete nodeKey;
                return true;
            }
        }


        // // case 2: has one child
        // //       (O) nodeParent   (O)
        // //       /                  \ 
        // //     (X) nodeKey     o    (X) ...
        // //     /                    /
        // //    O                    O
        else if ((*nodeKey).left == nullptr || (*nodeKey).right == nullptr) {
            TreeNode *nodeChild = nodeKey;
            // if has left child
            if ((*nodeKey).right == nullptr) {
                nodeChild = (*nodeKey).left;
            }
            else {
                nodeChild = (*nodeKey).right;
            }
            (*nodeKey).val = (*nodeChild).val;
            (*nodeKey).left = (*nodeChild).left;
            (*nodeKey).right = (*nodeChild).right;
            delete nodeChild;
            return true;
        }
    

        // // case 3: has two children (left child doesn't have right child)
        // //       (O)  nodeParent               (O)
        // //       /                               \ 
        // //     (X)    nodeKey       or           (X)
        // //     / \                               / \ 
        // //    O   O                             O   O
        // //   /                                 /
        // //  O                                 O
        else if ((*(*nodeKey).left).right == nullptr) {
            // Find the left child of the nodeKey
            TreeNode *nodeChild = (*nodeKey).left;
            // copy child value and left pointer to node value;
            (*nodeKey).left = (*nodeChild).left;
            (*nodeKey).val = (*nodeChild).val;
            // delete child
            delete nodeChild;
            return true;
        }


        // // case 4: has two children (left child has right child)
        // //       (O)  nodeParent               (O)
        // //       /                               \ 
        // //     (X)    nodeKey       or           (X)    ...
        // //     / \                               / \ 
        // //    O   O   nodeChild                 O   O
        // //   / \                               / \ 
        // //  O   O     nodeMax                 O   O
        // //                                         \ 
        // //                                          O  nodeMax
        else {
            TreeNode *nodeChild = (*nodeKey).left;
            TreeNode *nodeMax = (*nodeChild).right;
            // Find the max node under left child subtree (deepest)
            while ((*nodeMax).right != nullptr) {
                nodeChild = nodeMax;
                nodeMax = (*nodeChild).right;
            }
            // re-link nodes that are originally linked to the nodeKey to new nodeMax 
            // copy nodemax value to nodekey
            (*nodeKey).val = (*nodeMax).val;
            // set nodechild pointer to nodemax as nullptr
            (*nodeChild).right = nullptr;
            // delete nodeMax
            delete nodeMax;
            return true;
        }
    }
    else {
        return false;
    }
}

bool BST::isEmpty() {
    return empty_;
}

std::vector<int> BST::toVector() {
    TreeNode *node = root_;
    std::vector<int> out = {};
    std::queue<TreeNode*> children = {};
    if (empty_ == true) {
        return out;
    }
    else {
        children.push(root_);
        while (children.size() != 0) {
            node = children.front();
            out.push_back((*node).val);
            if ((*node).left != nullptr) {
                children.push((*node).left);
            }
            if ((*node).right != nullptr) {
                children.push((*node).right);
            }
            children.pop();
        }
    }
    return out;
}

int BST::depth() {
    if (empty_ == true) {
        return 0;
    }
    else {
        return getMaxLevel(root_, 1, 1);
    }
}

int BST::getMaxLevel(TreeNode *node, int levelCurr, int levelMax) {
    if (node->left != nullptr) {
        levelMax = getMaxLevel(node->left, levelCurr + 1, levelMax);
    }
    if (node->right != nullptr) {
        levelMax = getMaxLevel(node->right, levelCurr + 1, levelMax);
    }
    return (levelCurr > levelMax) ? levelCurr : levelMax;
}


std::vector<int> BST::toInorder() {
    TreeNode *node = root_;
    std::vector<int> orderedVec = {};
    if (empty_ == true) {
        return orderedVec;
    }
    else {
        std::stack<TreeNode*> nodeStack;
        while (node != nullptr || !nodeStack.empty()) {
            nodeStack.push(node);
            if (node != nullptr) {
                node = node->left;
            }
            else if (!nodeStack.empty()){
                nodeStack.pop();
                orderedVec.push_back(nodeStack.top()->val);
                node = nodeStack.top()->right;
                nodeStack.pop();
            }
        }
        return orderedVec;
    }
}


std::vector<int> BST::toInorderRec() {
    std::vector<int> orderedVec = {};
    if (empty_ == true) {
        return orderedVec;
    }
    else {
        return getOrderedVecRec(root_);
    }
}


std::vector<int> BST::getOrderedVecRec(TreeNode *node) {
    std::vector<int>  currVec = {node->val};
    if (node->left != nullptr) {
        std::vector<int> newVec = getOrderedVecRec(node->left);
        currVec.insert(currVec.begin(), newVec.begin(), newVec.end());
    }
    if (node->right != nullptr) {
        std::vector<int> newVec = getOrderedVecRec(node->right);
        currVec.insert(currVec.end(), newVec.begin(), newVec.end());
    }
    return currVec;
}