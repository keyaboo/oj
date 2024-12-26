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
