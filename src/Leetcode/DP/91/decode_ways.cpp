#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int numDecodings(string s);

int main() {
    fast; 
    int t = 3;  
    string line;
    while(t--) {
        getline(cin, line);
        string str = line.substr(1, line.length() - 2);

        cout << numDecodings(str) << endl; 
    }
    return 0;
}


int numDecodings(string s) {
    int n = s.length();
    if (n == 0 || s[0] == '0') return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        if (s[i-1] != '0') { // remember to ta
            dp[i] += dp[i-1];
        }
        int val = stoi(s.substr(i-2, 2));
        // cout << val << "\n";
        if (val >= 10 && val <= 26)
            dp[i] += dp[i-2];

        if (dp[i] == 0) {
            return 0;
        }
    
        }

    return dp[n];

}

/*
remember to check for characters.
*/