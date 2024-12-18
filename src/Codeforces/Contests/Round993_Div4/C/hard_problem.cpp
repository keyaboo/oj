#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int solve(int m, int a, int b, int c);
int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        cout << solve(m, a, b, c) << endl; 
    }

    return 0;
}

int solve(int m, int a, int b, int c) {
    int m1 = m;
    int m2 = m;
    int count = 0;
    if (a <= m1) {
        count += a;
        m1 = m1 - a;
    } else {
        count += m1;
        m1 = 0;
    }
    if (b <= m2) {
        count += b;
        m2 = m2 - b;
    } else {
        count += m2;
        m2 = 0;
    }
    m1 = m1 + m2;
    // cout << "m3: " << m1 << " count: " << count << endl;
    if (c <= m1) {
        count += c;
    } else {
        count += m1;
    }
    return count;
}