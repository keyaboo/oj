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
    for (int layer = 0; layer < min(n / 2, m / 2); layer++) {
        int i = layer;
        int j = layer;
        int dir = 0;
        while (dir < 4) {
                // cout << "Layer: " << layer << " i: " << i << " j: " << j << endl;
                layers[i][j] = layer;
                int newi = i + directions[dir][0];
                int newj = j + directions[dir][1];
                if (newi < layer || newi >= n - layer || newj < layer || newj >= m - layer) {
                    dir++;
                    newi = i + directions[dir][0];
                    newj = j + directions[dir][1];
                }
                i = newi;
                j = newj;
            }
    }
    // printMatrix(layers);
    vector<int> favorite = {1, 5, 4, 3};
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                int layer = layers[i][j];
                queue<pair<pair<int, int>, int>> queue;
                queue.push({{i, j}, 0});
                while (!queue.empty()) {
                    pair<pair<int, int>, int> front = queue.front(); queue.pop();
                    int row = front.first.first;
                    int col = front.first.second;
                    int idx = front.second;
                    if (matrix[row][col] == favorite[idx] && layers[row][col] == layer) {
                        if (idx + 1 == favorite.size()) {
                            total++;
                            break;
                        }
                        vector<int> dirOptions;
                        if (row < n/2 && col < m/2) { // Quadrant 1
                            dirOptions = {0, 3};
                        } else if (row < n/2 && col >= m/2) { // Quadrant 2
                            dirOptions = {0, 1}; // Right or Down
                        } else if (row >= n/2 && col >= m/2) { // Quadrant 3
                            dirOptions = {1, 2};
                        } else { // Quadrant 4
                            dirOptions = {2, 3};
                        }

                        for (int k = 0; k < dirOptions.size(); k++) {
                            int newrow = row + directions[dirOptions[k]][0];
                            int newcol = col + directions[dirOptions[k]][1];
                            if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m) {
                                queue.push({{newrow, newcol}, idx + 1});
                            }
                        }
                    } 
                }
            }
        }
    }
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
*/