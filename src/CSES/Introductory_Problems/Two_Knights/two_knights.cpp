#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
static long configure(int n);

/*
Maybe it's 6^n power minus some constant which may or may not be influenced by the previous value. No definitely not.
k^2 choose 2 minus some constant.
nCr=n!(n−r)!r! C r n = n ! / ( n - r ) ! r ! 
that constant is 8 * 2 * 2^(n-3) because going in both directions when n > 3. these numbers get wild pretty quickly,
wondering if there's some cancel or if the k^2 choose 2 can be just multiplied by some constant like this is.
the second constant is wrong, it's going from 8 -> 24 -> 48 -> 80 so 4 * 2^(n-2)? 
*/
int main() {
    fast; 
    int n; 
    cin >> n; 
    long res = configure(n);
    vector<long long> factorial;
    long long factorial = 1LL;
    for (int i = 0; i < n; i++) {

    }
    printf("%lld\n",x);
    cout << res << endl;
    return 0;
}

static long configure(int n) {
    return 0;
}
