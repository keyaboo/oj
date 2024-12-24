#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

void printMatrix(const vector<vector<int>>& matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int solve(vector<vector<int>>& matrix) {
    int directions[][2] = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> layers(n, vector<int>(m, -1));
    vector<int> seq;
    vector<int> favorite = {1, 5, 4, 3};
    int total = 0;

    for (int layer = 0; 2 * (layer + 1) <= n && 2 * (layer + 1) <= m; layer++) {
        // cout << "\n layer: " << layer << endl;
        seq.clear();
        for (int j = layer; j < m - layer; j++) seq.push_back(matrix[layer][j]);
        for (int i = layer + 1; i < n - layer - 1; i++) seq.push_back(matrix[i][m - layer - 1]);
        for (int j = m - layer - 1; j >= layer; j--) seq.push_back(matrix[n - layer - 1][j]);
        for (int i = n - layer - 2; i >= layer + 1; i--) seq.push_back(matrix[i][layer]);
        // cout << "seq size: " << seq.size() << endl;
        for (int k = 0; k < seq.size(); k++) {
            if (seq[k] == 1 && seq[(k+1) % seq.size()] == 5 && seq[(k+2) % seq.size()] == 4 && seq[(k+3) % seq.size()] == 3) {
                total++;
            }
        }
    }
    // printMatrix(layers);
    return total;
}

int main() {
    fast; 
    int t; 
    cin >> t; 
    cin.ignore();
    while(t--) {
        int n, m;
        cin >> n >> m;
        cin.ignore();
        vector<string> lines;
        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            lines.push_back(line);
        }
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            string row = lines[i];
            for (int j = 0; j < m; j++) {
                matrix[i][j] = row[j] - '0';
            }
        }
        int res = solve(matrix);
        cout << res << endl;
    }

    return 0;
}

/*
i think for a given index pair i, j you have a way of determining what layer you're in. the cyclic 1543 part is trivial

matrix n, m the outermost layer is going to be 0,0 - 0,m-1 : 0, m-1 - n-1, m-1 : n-1, 0 : n-1, m-1 : 0, 0 : 0, n-1

oh they're all even numbers that makes things easier. I could just save a matrix.
now that I made it to the bfs part, uhh
I'm overcounting noooooooo this is so hard. need directions specific to > m/2 or whatever.

I liked the way I originally did this so much more but it missed 1 test case :(
*/