#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int solve(string& a, string& b);
int main() {
    fast; 
    int t; 
    cin >> t;
    string a, b;
    while(t--) {
        cin >> a;
        cin >> b;
        cin.ignore();
        int res = solve(a, b);
        cout << res << endl;
    }
    return 0;
}

int solve(string& a, string& b) {
    int m = a.length();
    int n = b.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    return m + n - (2 * maxLen);;
}

/*
I guess you'd find the interval of longest overlap. longest substring match
or whatever LC problem that fails if it's O(n^2), will look that up.
oh because you have to use dynamic programming that's why.

forget what it was that a naive brute force led to TLE but this is O(m * n)
*/