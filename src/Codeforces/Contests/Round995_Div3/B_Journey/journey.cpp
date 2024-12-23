#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        vector<int> kilo = {a, b, c};
        int sum = accumulate(kilo.begin(), kilo.end(), 0);
        int rem = n % sum;
        int cycles = n / sum;
        int days = cycles * 3;
        int idx = 0;
        int total = 0;
        while (total < rem) {
            total += kilo[idx];
            days++;
            idx = ((idx + 1) % 3);
        }
        cout << days << endl;
    }

    return 0;
}

/*

*/