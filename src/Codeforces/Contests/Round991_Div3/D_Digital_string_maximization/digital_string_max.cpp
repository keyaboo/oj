#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
static void solve(string& s);
/*
so a candidate for swapping would be s[i+k] - s[i] > k or something like that.
but it's probably worse than that because s[i+1] might be replaced with something
smaller than necessary if you look too far away.

1709 -> 6109

zeroes should always move as far to the right as possible. the regular algo probably catches.

1490 -> 7210 I think is the answer - no you can do better.
1490 -> 3190 -> 3810 -> 7310
10009 -> 10080 -> 10700 -> 16000 -> 51000
this suggests going in the other direction could be preferable. but actually you could probably
start a loop with 0, go from the left, perform all swaps. actually coming from the right no number > 1
would ever be swapped.


if there's a zero in between this presents a problem since you could end up double decrementing
with the way I did 'solve'. will come back to this in a bit. perhaps move zeroes to end could
go on top of this. or they could all be moved at the beginning.

things I did wrong: don't store best k, store the max value at best k and whatever that index happens to be.
you don't swap the values at best k and i directly, there's no decrement penalty for shifting things to 
the right, only to the left. so the best value is saved and put at s[i]. but information on the old s[i]
isn't suddenly irrelevant.
*/

int main() {
    fast; 
    int t; 
    cin >> t; 
    cin.ignore();
    string line;
    while(getline(cin, line)) {
        string s = line;
        solve(s);
        cout << s << endl;
    }

    return 0;
}


static void solve(string& s) {
    int len = s.length();
    for (int i = 0; i < len; i++) {
        int best = s[i] - '0';
        int idx = i;
        for (int k = 1; k < 10 && i+k < len; k++) { // stopping this prematurely
            int candidate = s[i+k] - '0' - k;
            if (candidate > best) {
                best = candidate;
                idx = i+k;
            }
        }
        for (int j = idx; j > i; j--) {
            swap(s[j], s[j - 1]);
        }
        s[i] = char(best + '0');
        }
        
    }
