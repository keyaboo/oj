#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int n, k;
        cin >> n >> k;
        map<long long, pair<long long, long long>> treemap;
        for (int i = 0; i < n; i++) {
            int g; cin >> g;
            treemap[g].first++; // first is good
        }

        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            treemap[b].second++; // second is bad
        }
        int total = n;
        int negative = 0;
        long long res = 0;
        for (auto& kv : treemap) {
            if (negative <= k) {
                res = max(res, (long long) total * kv.first);
            }
            negative += (kv.second.second - kv.second.first);
            total -= kv.second.second; 
            // this is where the problem was: need to remove price points of customers no longer willing to buy
            // since in the next iteration you'll exceed whatever price you were looking at. 
        }
        cout << res << endl;
    }

    return 0;
}

/*
no more than k negative reviews. so the first candidate would be 
4 3
2 3 2 8
3 7 3 9
the answer for this is 14
candidates need to exceed bad ratings. 
*/
