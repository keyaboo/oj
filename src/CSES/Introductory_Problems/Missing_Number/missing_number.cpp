#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    long n; 
    cin >> n; 
    long sum = (((n + 1) * n) / 2); 
    n -= 1;
    while((n)--) {
        long a;
        cin >> a;
        sum -= a;
    }
    cout << sum << endl; 
    return 0;
}
