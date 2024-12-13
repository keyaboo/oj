#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

/*
there's probably some symmetry trick here. nah probably a dp table with
size n^2, maybe n + 1 squared. 1 - arr[i] flips 0/1. no dp table actually.
in java it would be system.arraycopy the
*/
int main() {
    fast; 
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> arr(n, 0);

            for (int j = 0; j < i; j++) {
                arr[i] = 1;
            }
        }

    }
    return 0;
}
