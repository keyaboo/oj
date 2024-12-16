#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int perfectSum(vector<int>& arr, int target);

int main() {
    int numTestCases;
    cin >> numTestCases; 
    cin.ignore(); // Ignore the newline after reading numTestCases

    for (int t = 0; t < numTestCases; ++t) {
        int numPairs;
        cin >> numPairs;
        cin.ignore(); // Ignore the newline

        vector<vector<int>> classes;
        for (int i = 0; i < numPairs; ++i) {
            string line;
            getline(cin, line); 
            vector<int> classPair;
            stringstream ss(line);
            int num;
            while (ss >> num) {
                classPair.push_back(num);
            }
            classes.push_back(classPair);
        }

        int extraStudents;
        cin >> extraStudents;
        cin.ignore(); // Ignore the newline


        // Process the current test case 
        cout << "Test Case " << t + 1 << endl;
        for (const auto& classPair : classes) {
            for (int num : classPair) {
                cout << num << " "; 
            }
            cout << endl;
        }
        cout << "Extra students: " << extraStudents << endl;
    }

    return 0;
}

    int perfectSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(k+1,0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            int num = arr[i - 1]; // this is where you're liable to make a mistake.
            for (int j = 0; j <= k; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][k];
    }

/*
you use the 2d array to avoid double counting by ensuring that each subset is counted
exactly once.
*/