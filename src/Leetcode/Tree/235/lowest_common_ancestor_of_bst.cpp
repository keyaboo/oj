#include <bits/stdc++.h> 
#include "tree.h"
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);

int main() {
    fast; 
    int t = 3;  
    string line;
    while(t--) {
        getline(cin, line);
        string temp;
        int pval, qval;
        cin >> pval >> qval;
        cin.ignore();
        stringstream ss(line.substr(1, line.size() - 2));
        vector<int*> values;
        while (getline(ss, temp, ',')) {
            if (temp == "null") {
                values.push_back(nullptr);
            } else {
                int* val = new int(stoi(temp));
                values.push_back(val);
            }
        }
        TreeNode* root = createTreeFromValues(values);
        cout << endl;
        cout << "\np " << pval << " q " << qval << endl;
        // TreeNode* = lowestCommonAncestor(root, )
        TreeNode* p = searchTreeNode(root, pval);
        TreeNode* q = searchTreeNode(root, qval);
        TreeNode* res = lowestCommonAncestor(root, p, q);
        printTreeLevelOrder(res);
        deleteTree(root);
    }
    return 0;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val > p->val && root->val > q->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;       
}

/*
oh it's a BST I neglected to notice that. If it's either less than or greater than
both ancestors we'll need to shift, the alternative will return the node itself
which the problem states is fine it can be its own descendant.
*/