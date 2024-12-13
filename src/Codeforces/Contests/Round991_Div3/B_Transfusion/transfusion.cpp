#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
static bool canTransfuse(vector<int>& arr); 

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
