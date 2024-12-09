#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    long n; 
    cin >> n; 
    while (n > 1) {
        cout << n << " ";
        if (n & 1 == 1) {
            n = 1 + 3 * n;
        } else {
            n /= 2;
        }
    }
    cout << 1 << endl;

    return 0;
}
