#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int n;
        cin >> n;
        vector<int> problemsa(n);
        vector<int> problemsb(n);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            problemsa[i] = a;
        }

        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            problemsb[i] = b;
        }
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            if (problemsa[i] > problemsb[i+1]) {
                res += (problemsa[i] - problemsb[i+1]);
            }
        }
        res += problemsa[n-1];
        cout << res << endl; 
    }

    return 0;
}
/*

*/