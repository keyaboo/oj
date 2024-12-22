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
        vector<int> brandTotal(k, 0);
        int b, c;
        for (int i = 0; i < k; i++) {
            cin >> b >> c;
            brandTotal[b-1] += c;
        }
        sort(brandTotal.begin(), brandTotal.end(), greater<>());
        long long total = 0;
        for (int i = 0; i < min(n, k); i++) {
            total += brandTotal[i];
        }
        cout << total << endl;
    }

    return 0;
}

/*
oh I see it's like coke and diet coke are the same, there are no quantities.
the min approach was good.
*/