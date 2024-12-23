#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

long long solve(vector<long long>& seq, long long x, long long y) {
    long long res = 0LL;
    long long sum = accumulate(seq.begin(), seq.end(), 0LL);
    // cout << "sum " << sum << " maximum: " << maximum << " minimum: " << minimum << endl;
    sort(seq.begin(), seq.end());
    // for (int i = 0; i < seq.size(); i++) cout << seq[i] << " ";
    for (int i = 0; i < seq.size(); i++) { // lower_bound & upper_bound already take care of OOB, originally -2 (which was stupid)
        long long targetmax = sum - x - seq[i];
        long long targetmin = sum - y - seq[i];
        auto lower = lower_bound(seq.begin() + i + 1, seq.end(), targetmin);
        auto upper = upper_bound(seq.begin() + i + 1, seq.end(), targetmax);
        res += distance(lower, upper);
        // just use the stl lol. these return iterators, not indices that point to the first element in the range greater than or equal to targetmin.
    }
    return res;
}

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int n;
        long long x, y;
        cin >> n >> x >> y;
        vector<long long> seq;
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            seq.push_back(a);
        }
        long long res = solve(seq, x, y);
        cout << res << endl;
    }

    return 0;
}
/*
not sum of sequence past i excluding j, it's the entire sequence sum.
there are some binary search problems that justify writing the whole low < high stuff this isn't one of them.
*/