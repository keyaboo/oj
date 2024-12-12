#include <bits/stdc++.h> 
#include <string>
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
static bool solve(string s);
/*
for all digits 1,2,3 square them I guess. breadth first search I guess. there's nothing about the ones place number
that would suggest it's divisible by 9 so brute force would be the only way. oh sum of lengths doesn't exceed 10^5 lol.
you could substring a tiny portion. if a number has 9 trailing 0's I'm assuming it would be divisible by 9.
actually 1 less than that number would be divisible by 9. so 2222222000000000 -> 2222221999999999 + 1.
the way to think about it is the other way around, that number with the trailing 9s isn't even divisible by 9, 9 0's don't matter.

9 as binary will be 1001. 8 would be 1000, which may be a better candidate than 10 to go looking for prospects. & 8.

divisibility rule of 3 hahaha there's another one for 9, wasn't expecting that to ever come up again.
I just don't really know how to do the dp part, ok you don't immediately check whether the sum is divisible by 9. the dp truth
table comes first. if every single digit is a 3, you'd get every index and multiply the size of that by 6.

failed the test case for an absurdly high number because dp table got too big.
*/

int main() {
    fast;
    int t; 
    cin >> t; 
    cin.ignore();
    string line;
    while(getline(cin, line)) {
        string s = line;
        // cout << s << endl;
        if (solve(s)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}

static bool solve(string s) {
    int len = s.length();
    vector<int> indices;
    long long sum = 0;
    for (size_t i = 0; i < s.length(); i++) {
        int val = s[i] - '0';
        sum += val;
        if (val == 2 || val == 3) {
            indices.push_back(i);
        }
    }
    if (sum % 9 == 0) return true;
    sum %= 9; // had to add this to keep the memory down.
    vector<vector<bool>> dp(indices.size() + 1, vector<bool>(9, false));
    // set the base case that the sum can be reached.
    dp[0][sum] = true; // think this is how you do this.
    for (int i = 1; i <= indices.size(); i++) { // this is super easy to get wrong because every access to indices is i - 1
        int change = (s[indices[i-1]] == '2') ? 2 : 6;
        for (int j = 0; j < 9; j++) { // this loop originally: int j = sum; j <= sum + 6 * indices.size(); j++
            dp[i][j] = dp[i-1][j];
            if (dp[i - 1][(j - change + 9) % 9]) { // bounds check and verifying that the previous number could be reached.
                dp[i][j] = true;
                if (j == 0) {
                    return true;
                }
            }
        }
    }

    return false;
}
