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

edit: 

the L's are always aligned. I was confused about how access would work if distance was three
but it would be accessing everything in the first column.
*/

vector<int> solve(vector<pair<int, int>>& queries, vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
        return vector<int>(queries.size(), 0);
    }
    vector<int> diff(n - 1); 
    for (int i = 1; i < n; ++i) {
        diff[i - 1] = abs(nums[i] - nums[i - 1]);
    }
    
    int k = log2(n - 1) + 1; 
    vector<vector<int>> st(n-1, vector<int>(k));
    for (int i = 0; i < n - 1; ++i) {
        st[i][0] = diff[i];
    }

    for (int j = 1; j < k; ++j) { 
        for (int i = 0; i + (1 << j) <= n - 1; i++) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }    

    vector<int> res(queries.size(), 0);

    for (int i = 0; i < queries.size(); ++i) {
        int l = queries[i].first - 1;
        int r = queries[i].second - 1;
        if (l == r) {
            res[i] = 0;
            continue;
        }
        r--; // this is because first col holds only diffs
        int j = log2(r - l + 1);
        res[i] = gcd(st[l][j], st[r - (1 << j) + 1][j]);
    }
    
    return res;
    
}
