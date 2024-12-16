#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int perfectSum(vector<int>& arr, int target);

int main() {
    fast; 
    int t; 
    cin >> t; 
    cin.ignore();

    while(t--) {
        vector<int> arr;
        int target;
        string inputLine;
        getline(cin, inputLine);
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }
        cin >> target;
        cin.ignore();
        int res = perfectSum(arr, target);
        cout << res << endl;
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
                dp[i][j] = dp[i-1][j];
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