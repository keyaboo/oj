#include <bits/stdc++.h>
#include <string> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

/*
seems like 1 & 2 always make it into one group and 3 into another, n - 3 has to be divisible by 4
4 is the odd one. 
no it isn't there are 2 patterns, the one based on 7 and the one based on 4. 
*/

int main() {
    fast; 
    int n;
    cin >> n;
    if ((n - 3) % 4 == 0) {
        cout << "YES" << endl;
        cout << ((n/2) + 1) << endl;
        cout << 1 << " " << 2 << " ";
        for (int i = 4; i <= n; i += 4) {
            cout << i << " " << (i+3) << " ";
        }
        cout << endl << (n/2) << endl << 3 << " ";
        for (int i = 5; i < n; i += 4) {
            cout << i << " " << (i+1) << " ";

        }
    } else if (((n % 4) == 0)) {
        cout << "YES" << endl;
        cout << ((n/2)) << endl;
        cout << 1 << " " << 4 << " ";
        for (int i = 5; i < n; i+= 4) {
            cout << i << " " << (i+3) << " ";
        }
        cout << endl << (n/2) << endl << 2 << " " << 3 << " ";
        for (int i = 6; i < n; i += 4) {
            cout << i << " " << (i+1) << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

