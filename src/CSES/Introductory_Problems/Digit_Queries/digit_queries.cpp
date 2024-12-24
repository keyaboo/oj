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
        long long p = 168;
        long long res = solve(p);
        cout << res << endl; 

    return 0;
}

long long solve(long long q) {
    if (q < 10) {
        return q;
    }
    long long power = 0;
    long long startpos = 0;
    // cout << "what's the number " << pow(10, power) << " " << endl;
    vector<long long> rangestarts;
    rangestarts.push_back(startpos);
    while (rangestarts[rangestarts.size() - 1] < 1e18) {
        power++;
        // cout << "power" << power << endl;
        long long newbase = 1;
        for (int i = 0; i < power; i++) {
            newbase *= 10;
        }
        for (int i = power - 1; i >= 0; i--) {
            newbase -= (long long) pow(10, i);
        }
        startpos = rangestarts[rangestarts.size() - 1] + 1 +  (power * newbase);
        cout << "this thing " << rangestarts[rangestarts.size() - 1] << "newbase: " << newbase << " rangestart " << startpos << " power" << power << endl;
        rangestarts.push_back(startpos);
    }
    
    cout << rangestarts.size() << " rs size" << endl;
    cout << "first: " << rangestarts[0] << "second: " << rangestarts[1];
    int idx = 0;
    for (int i = rangestarts.size() - 1; i >= 0; i--) {
        if (q - rangestarts[i] >= 0) {
            idx = i;
            break;
        }
    }
    cout << "q mod 2" << (q % 2) << endl;
    cout << "q mod 1" << (q % 1) << endl;
    for (int i = idx + 1; i > 1; i--) {
        int val = q % i;
        cout << "q mod " << i << " " << val << endl;
    }

    cout << "idx happens to be " << idx << " rangestart at that index is " << rangestarts[idx] << " " << endl;; 
    q -= rangestarts[idx];

    cout << endl << "q: " <<  q << " interval " << idx << " " << endl;
    long long multiple = (long long) (idx + 1) * (pow(10, idx));
    cout << "multiple " << multiple << endl;
    int positionWithinGroup = q % multiple;

    int positionWithinNumber = positionWithinGroup % (idx + 1);

    long long number = (positionWithinGroup / (idx + 1))  + pow(10, idx);
    string numberStr = to_string(number);
    int digit = numberStr[positionWithinNumber] - '0';

    return digit;
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

194 - 189 = 5 100101 it's a 0 just as we expected
193 - 189 = 4 100101 it's a 1 first "101" as expected

repeat cycle is going to be every 3 (idx + 1) * 100 which is pow(10, idx+1)

ok I actually need to create the number
*/