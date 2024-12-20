#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
struct pair_hash {
  inline std::size_t operator()(const std::pair<int, int> &v) const {
    return v.first * 31 + v.second;
  }
};
vector<pair<int, int>> findTaken(const vector<vector<int>>& matrix, int i, int j);
int findPermutations(const vector<vector<int>>& matrix, int i, int j, unordered_set<pair<int, int>, pair_hash>& inaccessible);

int main() {
    fast; 
    int n = 8;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j) {
            if (line[j] == '*') {
                matrix[i][j] = 1;
            } 
        }
    }
    int res = 0;
    for (int j = 0; j < n; j++) {
        unordered_set<pair<int, int>, pair_hash> inaccessible;
        res += findPermutations(matrix, 0, j, inaccessible);
    }
    cout << res << endl;

    return 0;
}

int findPermutations(const vector<vector<int>>& matrix, int row, int col, unordered_set<pair<int, int>, pair_hash>& inaccessible) {
    if ((matrix[row][col] == 1 || inaccessible.count({row, col}) > 0)) {
        return 0;
    }
    if (row == matrix.size() - 1) {
        return 1;
    }
    vector<pair<int, int>> taken;
    for (int k = 1; row + k < matrix.size(); k++) {
        taken.push_back({row+k, col});
        if (col - k >= 0) {
            taken.push_back({row+k, col - k});
        }
        if (row + k < matrix.size()) {
            taken.push_back({row+k, col + k});
        }
    }
    vector<pair<int, int>> newlyBlocked;
    for (const auto& p : taken) {
        if (inaccessible.count(p) == 0) {
            inaccessible.insert(p);
            newlyBlocked.push_back(p);
        }
    }

    int count = 0;
    for (int nextJ = 0; nextJ < matrix[0].size(); nextJ++) {
        count += findPermutations(matrix, row + 1, nextJ, inaccessible);
    }
    for (const auto& p : newlyBlocked) {
        inaccessible.erase(p);
    }

    return count;
}
/*
I really wanted to do just one loop but it got so ugly.

"However, the reserved squares do not prevent queens from attacking each other."

the break statements are in direct conflict with this sentence but it was too much work
doing it this way that I don't mind preserving this version. it overcounts obviously.


*/

