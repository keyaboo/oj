#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int findPermutations(const vector<vector<int>>& matrix, int row, int col, vector<bool>& columns, vector<bool>& leftDiag, vector<bool>& rightDiag);

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
    vector<bool> leftDiag(2*n-1, false), rightDiag(2*n-1, false);
    vector<bool> columns(n, false);

    for (int j = 0; j < n; j++) {
            res += findPermutations(matrix, 0, j, columns, leftDiag, rightDiag);
    }
    cout << res << endl;
    return 0;
}
/*
EIGHT queens. sketching this out 4 by 4 it's clear that the placement of a queen
at the bottom row prohibits the selection at every other row by one or two plus the
same column can't be selected so 1 + 1 + (1?). recursive backtracking seems like the
most straightforward solution. I think you could have a pair<i, j> hashset.

found out hashsets are a pain because for a lot of data structure there isn't a default
hashing function.

I cheated a little bit here, the columns bool determines whether a queen has already been
placed in that column. But figuring out the diagonals which I took forever trying to get
to work with hashset pairs.

the diagonals are row + column. wow that's clever. and then it gets cleared with the backtrack.
I didn't know this but the key to backtracking is to undo the changes made by exploring a path
before moving onto the next possibility.

intuition behind the diagonal math: the sums of row + col and row - col + N - 1 map each cell on
the chessboard to a unique diagonal index within the range of 0 to 2N - 1. Just draw a line for
each of the diagonals of a 3 by 3 matrix and there are 5 of them in either direction.

*/
int findPermutations(const vector<vector<int>>& matrix, int row, int col, vector<bool>& columns, vector<bool>& leftDiag, vector<bool>& rightDiag) {
    if (row == matrix.size()) { // this out of bounds base case is crucial for the handling of the recursive call below.
        return 1;
    }
    if ((!(matrix[row][col] == 1 || columns[col] || leftDiag[row + col] || rightDiag[row - col + matrix.size() - 1]))) {
        return 0;
    }
    columns[col] = true;
    leftDiag[row + col] = true;
    rightDiag[row - col + matrix.size() - 1] = true;

    int count = 0;

    for (int j = 0; j < matrix[0].size(); j++) {
        count += findPermutations(matrix, row+1, j, columns, leftDiag, rightDiag);
    }
    // now backtrack to prevent this path from affecting others.
    columns[col] = false;
    leftDiag[row + col] = false;
    rightDiag[row - col + matrix.size() - 1] = false;

    return count;
}