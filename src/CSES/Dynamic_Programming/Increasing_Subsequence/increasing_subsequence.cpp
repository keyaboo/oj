#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int solve(vector<int> &nums);

int main() {
    fast; 
    int t = 1; 
    int n;

    while(t--) {
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            // cout << v[i] << " ";
        }
        cout << endl << solve(v) << endl; 
    }
    return 0;
}



int solve(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}




/*
Just have to identify the recurrence.
dp[] fills length of longest subsequence.
the value of an increase doesn't matter, what's important is that a prefix increase was counted.
recurrence: dp[i] = max(dp[i], dp[j] + 1) for j < i and nums[i] > nums[j].
*/