#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
static bool canTransfuse(vector<int>& arr); 
/*
I've seen this problem before. I think you just need to keep a running average as a float.
I remember the Math.ceil function got used. small prefix mean -> big is what we have to worry about.
no it was floor, and I think it needs to be greater than i.
I was reading this problem wrong, this wasn't the same as that one at all. got it wrong bc long long
*/

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        if (canTransfuse(nums)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}

static bool canTransfuse(vector<int>& arr) {
    long long odds = 0;
    long long evens = 0;
    int oddc = 0;
    int evenc = 0;
    for (size_t i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            odds += arr[i];
            oddc++;
        } else {
            evens += arr[i];
            evenc++;
        }
    }
    // check for remainders and equivalence
    if ((odds % oddc != 0) || (evens % evenc != 0) || ((odds / oddc) != (evens / evenc))) {
        return false;
    }
    return true;
}
