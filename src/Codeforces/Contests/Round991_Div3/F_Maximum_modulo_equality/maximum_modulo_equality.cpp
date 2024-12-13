#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
vector<int> solve(vector<pair<int, int>>& queries, vector<int>& nums);
int main() {
    fast; 
    int t; 
    cin >> t;
    
    while(t--) {
        int n, q;
        cin >> n >> q;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vector<pair<int, int>> queries;
        while(q--) {
            int l, r;
            cin >> l >> r;
            queries.push_back({l, r});
        }
        vector<int> res = solve(queries, nums);
        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
the queries are how many values represent subsets of the array, got it.
I think you would find gcd of all pairs, maybe have a bitmap or probably
just do the O(n^2) thing.

ok I think how you'd do this but it's too challenging to code up, find the
gcd for all pairs in the interval, add those to a vector. sort the vector

no, differences make everything relatable on a mod m == 0 level, which lets
you work with gcd in the first place. you can do this for the entire array
a1 - an, just store the diffs.

the sparse table is a 2d array with row dimensions n - 1 (because diffs was smaller),
and a constant k with the number of columns. the first column is filled with the diffs
then the next column finds the gcd of all the diffs. then the next column finds
the gcd of pairs from those (the numbers calculated is one fewer), then the next column
finds the gcd of those differences, again the calculations shrink.

*/

vector<int> solve(vector<pair<int, int>>& queries, vector<int>& nums) {
    int n = nums.size();
    vector<int> res(queries.size(), 0);
    if (n == 1) {
        return vector<int>(1,0); // one element array prevents segfault.
    }
    vector<int> diff(n - 1);  // Store differences of adjacent elements
    for (int i = 1; i < n; ++i) {
        diff[i - 1] = abs(nums[i] - nums[i - 1]);
    }
    
    // Sparse table
    int k = log2(n - 1) + 1; 
    vector<vector<int>> st(n-1, vector<int>(k));
    for (int i = 0; i < n - 1; ++i) {
        st[i][0] = diff[i];
    }
    // cout << st[0][0] << endl;
    for (int j = 1; j < k; ++j) { // Iterate over columns
        for (int i = 0; i + (1 << j) <= n - 1; ++i) { // Iterate over rows
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    cout << st[0][0] << endl;
    cout << st[0][1] << endl;
    cout << st[0][2] << endl;
    

    // Query processing
    for (int i = 0; i < queries.size(); ++i) {
        int l = queries[i].first - 1;
        int r = queries[i].second - 1;
        if (l == r) { // Handle single-element queries
            res[0] = 0;
            continue;
        }
        r--;
        int j = log2(r - l + 1);
        cout << "l " << l << " r " << r << " j " << j << endl;
        res[i] = gcd(st[j][l], st[r - (1 << j) + 1][j]);
    }
    
    return res;
    
}
