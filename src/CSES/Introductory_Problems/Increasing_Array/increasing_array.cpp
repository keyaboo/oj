#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    int n; 
    cin >> n;
    long count = 0;
    long curr; cin >> curr;
    long prev;
    for (long i = 1; i < n; i++) {
        prev = curr;
        cin >> curr;
        if (curr < prev) {
            long diff = prev - curr;
            count += diff;
            curr = prev;
        }
    }
    cout << count << endl;

    return 0;
}
