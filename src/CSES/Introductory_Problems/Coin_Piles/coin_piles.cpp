#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
static bool canRemove(int small, int big);
/*
seems like if 2a < b or whichever one is smaller, you couldn't do it.
pattern 2,2 seems like it's the thing to look at, because even with larger
numbers if we get a pair that isn't divisible by 3 it's going to be a problem.
my mistake was conceptually thinking the diff reductions would be bigger and
would magically make the difference between a, b two.
*/
int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int a, b;
        cin >> a >> b;
        if (canRemove(min(a,b), max(a,b))) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}


static bool canRemove(int small, int big) {
    if (big > 2*small) {
        return false;
    } else if (big == 2*small) {
        return true;
    }
    while (big - small > 2) {
        int diff = (big - small) / 2;
        // printf("%d\n", diff);
        big -= (2 * diff);
        small -= diff;
    }
    // printf("small=%d big=%d\n",small,big);
    if (small >= 3) {
        int constant = (small / 3);
        small -= constant * 3;
        big -= constant * 3;
    }
    // printf("small=%d big=%d\n",small,big);
    if (big == small && small == 0) {
        return true;
    } else if (small == 1 && big == 2) {
        return true;
    } else if (small = 2 && big == 4) {
        return true;
    }
    return false;
} 