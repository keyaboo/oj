#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
static long long findVal(long i, long j);

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        long a, b;
        cin >> a >> b;
        long long res = findVal(a, b);
        cout << res << endl;
    }

    return 0;
}

/*
pattern is the odd column matrix[0][j] = j^2. the even rows matrix[i][0] first value = i^2. find the bigger of the two, and subtract (i) from j^2 if j's odd or
(j) from i^2 if i is even. if j > i and j is even, add (i + 1) to (j-1) ^2, and if i > j and i is odd, add (j + 1) to (i - 1) ^2.
don't use pow() for some reason.
*/
static long long findVal(long i, long j) {
    if (j >= i) {
        if ((j % 2) == 1) {
            return (j*j) - i + 1; // 5, 2 good
        } else {
            return ((j-1)*(j-1)) + i; // 4, 2 good
        }
    } else {
        if ((i % 2) == 0) {
            return i * i - j + 1; // 4, 2 good
        } else {
            return ((i-1)*(i-1)) + j; // 5, 2 good
        }
    }
    return 0;
}
