#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int solve() {
    
}

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> good;
        vector<int> bad;
        for (int i = 0; i < n; i++) {
            int a; cin >> a;
            good.push_back(a);
        }
        for (int i = 0; i < n; i++) {
            int b; cin >> b;
            bad.push_back(b);
        } 
    }

    return 0;
}
