#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int n;
        cin >> n;
        int i = 1;
        n -= i;
        int count = 0;
        while(i <= n) {
            if (i != n) {
                count++;
            }
            i++;
            n--;
            count++;
        }
        cout << count << endl;
    }

    return 0;
}
