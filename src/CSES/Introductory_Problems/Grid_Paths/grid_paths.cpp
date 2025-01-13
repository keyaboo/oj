#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int solve(vector<int>& instructions, vector<vector<bool>> visited, int row, int col, int instructionIdx, int prevDir, int (*dir)[2]);
int main() {
    string what = "DRURDDLL";
    //string what = "????????";
    cout << what.size() << endl;
    fast; 
    string relative; 
    getline(cin, relative);
    int n = 3;
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int directions[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<int> instructions;
    for (int i = 0; i < what.size(); i++) {
        char c = what[i];
        if (c == 'R') {
            instructions.push_back(0);
        } else if (c == 'L') {
            instructions.push_back(2);
        } else if (c == 'D') {
            instructions.push_back(1);
        } else if (c == 'U') {
            instructions.push_back(3);
        } else if (c == '?') {
            instructions.push_back(-1);
        }
        cout << instructions[i] << " ";
    }
    cout << endl;
    int res = solve(instructions, visited, 0, 0, 0, -4, directions);
    cout << res << endl;
    return 0;
}

void printMatrix(const vector<vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (int val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}


int solve(vector<int>& instructions, vector<vector<bool>> visited, int row, int col, int instructionIdx, int prevDir, int (*dir)[2]) {
    if (row < 0 || row >= visited.size() || col < 0 || col >= visited.size()) {
        return 0;
    }
    if (visited[row][col] || (visited[visited.size() - 1][visited.size() - 1] && !visited[0][visited.size() - 1]) || row == visited.size() - 1 && col == 0 && instructionIdx < instructions.size() - 1
        || (visited[visited.size() - 2][0] && visited[visited.size() - 1][1] && instructionIdx < instructions.size()) ) {
        return 0;
    }
    if (row == visited.size() - 1 && col == 0 && instructionIdx == instructions.size()) {
        return 1;
    }
    visited[row][col] = true;
        cout << "row " << row << " col " << col << " instructionIdx " << instructionIdx << endl;
    int count = 0;
    if (instructions[instructionIdx] == -1) {
        set<int> dirs = {0, 1, 2, 3};
        if (row == 0) dirs.erase(3);
        if (col == 0) dirs.erase(2);
        if (row == visited.size() - 1) dirs.erase(1);
        if (col == visited.size() - 1) dirs.erase(0);
        for (int d = 0; d < 4; d++) {
        int newrow = row + dir[d][0];
        int newcol = col + dir[d][1];
        count += solve(instructions, visited, newrow, newcol, instructionIdx + 1, -4, dir);
        }
    } else {
        int newrow = row + dir[instructionIdx][0];
        int newcol = col + dir[instructionIdx][1];
        count += solve(instructions, visited, newrow, newcol, instructionIdx + 1, -4, dir);
    }
    visited[row][col] = false;
    return count;
}

/*
gotta be memoization for this one. base case 7, 0 return 1. have parameter instruction index, row/col
no that's too slow. 
Start with 88418 perhaps, there need to be net 7 down, 0 left right. but there has to be at least 3 ups
7 + 3 downs, at least 6 right and just as many lefts.

perhaps break this up into smaller problems, if you know that instruction 3 is 'L', there's only one
possible set of previous candidates for what instructions 1 and 2 are.

top right and bottom right corners need to be touched, and the order matters.

ok what about dp just make a matrix that stores 'ways' 0,0 is 1.

thinking about a 3 by 3 it seems your only paths are "DRURDDLL" and "RRDDLULD" 2 by 2 it's "RDL"
for 2 by 2, you're prevented from going straight down.

it would be so slow to explore all possibilities for current path if the only criteria is "the next
must be univisited" and it can't be the end square.

So it is memoization with backtracking I just didn't have the optimizations included.

- can't go in opposite direction of previous, but traversed dp should handle that.
- if on border, can't go outsid
*/