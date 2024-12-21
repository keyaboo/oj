#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
long long solve(long long k);
int main() {
    fast; 
    int q; 
    cin >> q; 

    while(q--) {
        long long k;
        cin >> k;
    }
        long long p = 19;
        long long res = solve(p);
        // cout << res << endl; 

    return 0;
}

long long solve(long long q) {
    int power = 1;
    long long rangestart = pow(10, power);
    cout << "what's the number " << pow(10, power) << " " << endl;
    vector<long long> rangestarts;
    rangestarts.push_back(rangestart);
    while (rangestart < 1e18) {
        power++;
        cout << "power" << power << endl;
        long long newbase = pow(10, power);
        for (int i = power - 1; i >= 0; i--) {
            newbase -= pow(10, i);
        }
        rangestart += (1 + power * newbase);
        cout << "newbase: " << newbase << " rangestart " << rangestart << endl;
        rangestarts.push_back(rangestart);
    }
    int i; // the interval under consideration
    for (i = 0; i < rangestarts.size(); i++) {
        cout << rangestarts[i] << " ";
        if (q - rangestarts[i] > 0) {
            q -= rangestarts[i];
        } else {
            break;
        }
    }
    int mod;
    while (q % (i + 1) != 0) {
    }
    cout << endl << "q: " <<  q << " interval " << i << " " << endl;
    return 0;
}

/*
there are 9 numbers from 0 - 9
for the two digits 10 - 99, there are 89 of them. range: 10, 10 + 89 * 2
for three digits 100 - 999 there are 899 of them. range: 11 + 89 * 2, 11 + 89 * 2
for digits > 10 but < 20, if the number % 2 == 0, it's 1, if
query % 2 == 1 it's number % 10


simpler question: how to get series 9, 89, 899 etc. it's 10^x - 10^(x-1) - ... (10^0)

1011121314
19 corresponds to the 4, q is a 9 when all the processing happens.

check that 9 < 20, it already is, but we'd want a new q lt 20. keep subtracting off (i + 1) * pow(10, i)
I think maybe modulo checks before all of that like if mod 2 == 0

ok, find out which modulo it is. you'd have to do for loops to get the digits. for i = 0; i * 20 < q; i++ for tens place
and for the next iteration i = 0; 2 * i < q; i++ for the ones place.

*/