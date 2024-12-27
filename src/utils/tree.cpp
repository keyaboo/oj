#include "tree.h"

TreeNode* createTreeFromValues(const std::vector<int*>& values) {
    if (values.empty()) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(*values[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    size_t i = 1; 

    while (!q.empty() && i < values.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (values[i] != nullptr) {
            curr->left = new TreeNode(*values[i]);
            q.push(curr->left);
        }
        i++;

        if (i < values.size() && values[i] != nullptr) {
            curr->right = new TreeNode(*values[i]);
            q.push(curr->right);
        }
        i++; 
    }

    return root;
}

void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void printTreeLevelOrder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr == nullptr) {
            std::cout << "null ";
        } else {
            std::cout << curr->val << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    std::cout << std::endl;
}

TreeNode* searchTreeNode(TreeNode* root, int value) {
    if (root == nullptr || root->val == value) {
        return root;
    }

    // Search in the left subtree
    TreeNode* leftResult = searchTreeNode(root->left, value);
    if (leftResult != nullptr) {
        return leftResult; 
    }

    return searchTreeNode(root->right, value);
}

// overkill, I'm only ever going to be using the first if
bool operator==(const TreeNode& lhs, const TreeNode& rhs) {
    // If the pointers are the same, they are equal
    if (&lhs == &rhs) {
        return true;
    }

    // If one is nullptr and the other isn't, they are not equal
    if (lhs.left == nullptr && rhs.left != nullptr) {
        return false;
    }
    if (lhs.left != nullptr && rhs.left == nullptr) {
        return false;
    }
    if (lhs.right == nullptr && rhs.right != nullptr) {
        return false;
    }
    if (lhs.right != nullptr && rhs.right == nullptr) {
        return false;
    }

    // Recursively compare the left and right subtrees
    bool leftEqual = (lhs.left == nullptr && rhs.left == nullptr) || 
                     (lhs.left != nullptr && rhs.left != nullptr && *lhs.left == *rhs.left);
    bool rightEqual = (lhs.right == nullptr && rhs.right == nullptr) ||
                      (lhs.right != nullptr && rhs.right != nullptr && *lhs.right == *rhs.right);

    // Check if the values and subtrees are equal
    return lhs.val == rhs.val && leftEqual && rightEqual;
}
