#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
long long solve(long long q);
long long power(long long a, long long b);
vector<long long> getRanges();
int main() {
    fast; 
    int t; 
    cin >> t; 
    cout << endl;
    while(t--) {
        long long k;
        cin >> k;
        long long res = solve(k);
        cout << res << endl;
    }
        // 
        //
    return 0;
}

// std::pow breaks down at the ~15 digit mark or so, this is safer.
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a);
        }
        a = (a * a);
        b >>= 1;
    }
    return res;
}


long long solve(long long k) { // called this q before I guess.
    long long digits = 1;
    long long base = 9;

    while (k - digits * base > 0) {  
        k -= digits * base;         
        base *= 10; // 9, 90, 900...
        digits++;
    }

    long long index = k % digits; // there is a number associated with digit k, and this finds the digits place of that number.              
    long long number = power(10, (digits - 1)) + (k - 1) / digits; 
    // first part gives us the first digit number (eg 10, 100)
    // this second part is what I was afraid to do because I was sticking with the k reassignment and didn't want to lose lower digits.
    // easy fix just make a new variable out of k, and since the numbers in the string have a 1-based index, divide by k - 1.
    // original k is always bigger than number just to think about it visually.
    
    // cout << " number is " << number << " k is: " << k << endl;
    if (index != 0) {
        number = number / power(10, digits - index); // this shifts the digit we're looking for to the units place.
    }
    return number % 10; // number % 10 will always extract the first digit (units place). At first I saw this and thought it
    // was leading digit but no, that's wrong. 
}

/*
*/