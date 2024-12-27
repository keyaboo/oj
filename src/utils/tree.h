// tree.h
#include <vector>
#include <queue>
#include <iostream>

#ifndef TREE_H
#define TREE_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool operator==(const TreeNode& lhs, const TreeNode& rhs);

TreeNode* createTreeFromValues(const std::vector<int*>& values);

void deleteTree(TreeNode* root);

void printTreeLevelOrder(TreeNode* root);

TreeNode* searchTreeNode(TreeNode* root, int value);


#endif