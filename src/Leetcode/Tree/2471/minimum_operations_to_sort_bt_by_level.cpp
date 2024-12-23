#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} 
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int minimumOperations(TreeNode* root);

void printIntPtrVector(const std::vector<int*>& values) {
    for (int* val : values) {
        if (val == nullptr) {
            std::cout << "null ";
        } else {
            std::cout << *val << " ";
        }
    }
    std::cout << endl;
}

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
    std::cout << endl;
}


int main() {
    fast; 
    int t = 3; 
    string line;
    while(t--) {
        getline(cin, line);
        string temp;
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
        // printIntPtrVector(values);
        // printTreeLevelOrder(root);
        int res = minimumOperations(root);
        cout << res << endl;
        deleteTree(root);
    }
    return 0;
}

int minswaps(vector<int>& arr) {
    int n = arr.size();
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    unordered_map<int, int> positions;
    for (int i = 0; i < n; i++) {
        positions[arr[i]] = i;
    }
    int swaps = 0;
    for (int i = 0; i < n; i++) { // this is a loop over sorted in terms of what we care about.
        if (arr[i] != sorted[i]) {
            swaps++;
            int currIdx = positions[sorted[i]]; // look for where in the unsorted array it presently is.
            positions[arr[i]] = currIdx; // reassign it in the map
            swap(arr[i], arr[currIdx]); // do a swap
        }
    }
    return swaps;
}

int minimumOperations(TreeNode* root) {
    int count = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> levelValues;
        int levelsz = q.size(); // size_t implicit conversion.
        for (int i = 0; i < levelsz; i++) { // bounds already limit it to just a given level.
            TreeNode* curr = q.front(); q.pop();
            levelValues.push_back(curr->val);
            if (curr->left != nullptr) q.push(curr->left);
            if (curr->right != nullptr) q.push(curr->right);
        }
        count += minswaps(levelValues);
    }
    return count;
}

/*
strictly increasing order. so level-order traversal and preserve the values in a vector.
I tried to jump by 2 for the entire thing but that wasn't actually aligned. you can process
the entire level inside the while loop I didn't realize that. we do a kind of selection sort
on the levelValues vector.

nvm that's worse than what the editorial suggests.
*/