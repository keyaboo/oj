#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
static long configure(int n);

/*
it's (n^2 choose 2) - (2(n-2))^3 but calculating that n^2 choose 2 efficiently I had to look up how to do.
no that second thing is wrong, the pattern 8 -> 24 -> 48 -> 80.
80 -> 5 * 16, 48 -> 4 * 12, 24 -> 3 * 8, 120 -> 6 * 20
24 -> 3 * (0 + 8), 48 -> 4 * (4 + 8), 80 -> 5 * (8 + 8), 120 -> 6 * (12 + 8) 
*/
int main() {
    fast; 
    int n; 
    cin >> n; 
    cout << 0 << endl;
    if (n >= 2) {
        cout << 6 << endl;
    }
    for (int i = 3; i <= n; i++) {
        long long spots = (pow(i, 4) - pow(i,2)) / 2;
        long long horses =  (i - 2) * (8 + 4 * (i - 3));
        long long ways = spots - horses;
        cout << ways << endl;
    }
    return 0;
}

