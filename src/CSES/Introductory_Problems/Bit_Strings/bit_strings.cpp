#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define MOD (int)(1e9 + 7) 

/*
is this not just 2^n? store as a long long. is this just the efficient power problem.
no it's not even long long overflows.
*/

int main() {
    fast; 
    int n; 
    cin >> n; 
    long base = 2;
    long pow = 1;
    while (n > 0) {
        if ((n % 2) == 1) {
            pow *= (base);
            pow %= MOD;
            n--;
        } else {
            n /= 2;
            base *= base;
            base %= MOD;
        }
    }
    cout << pow << endl;
    return 0;
}
