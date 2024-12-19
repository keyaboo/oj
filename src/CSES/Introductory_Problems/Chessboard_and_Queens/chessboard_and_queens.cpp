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
/*
EIGHT queens. sketching this out 4 by 4 it's clear that the placement of a queen
at the bottom row prohibits the selection at every other row by one or two plus the
same column can't be selected so 1 + 1 + (1?). recursive backtracking seems like the
most straightforward solution. I think you could have a pair<i, j> hashset.
*/
int findPermutations(const vector<vector<int>>& matrix, int i, int j, unordered_set<pair<int, int>, pair_hash>& inaccessible) {
    if (i == matrix.size()) {
        return 1;
    }
    if (matrix[i][j] == 1 || inaccessible.count({i, j}) > 0) {
        return 0;
    }
    vector<pair<int, int>> taken = findTaken(matrix, i, j);
    for (const auto& p : taken) {
        inaccessible.insert(p);
    }

    int count = 0;
    for (int nextJ = 0; nextJ < matrix[0].size(); nextJ++) {
        count += findPermutations(matrix, i + 1, nextJ, inaccessible);
    }
    for (const auto& p : taken) {
        inaccessible.erase(p);
    }

    return count;
}
/*
I really wanted to do just one loop but it got so ugly.
*/
vector<pair<int, int>> findTaken(const vector<vector<int>>& matrix, int i, int j) {
    vector<pair<int, int>> taken;
    for (int k = 1; i + k < matrix.size(); k++) {
        taken.push_back({i+k, j});
        if (matrix[i+k][j] == 1) {
            break;
        }
    }

    for (int k = 1; j - k >= 0 && i + k < matrix.size(); k++) {
        taken.push_back({i+k, j - k});
        if (matrix[i+k][j-k] == 1) {
            break;
        }
    }

    for (int k = 1; j + k < matrix[0].size() && i + k < matrix.size(); k++) {
        taken.push_back({i+k, j + k});
        if (matrix[i+k][j+k] == 1) {
            break;
        }
    }
    return taken;
}


