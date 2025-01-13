#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
bool canBeValid(string& s, string& locked);

int main() {
    fast; 
    int t = 3;
    string line1, line2;
    while(t--) {
        getline(cin, line1);
        getline(cin, line2);
        string s = line1.substr(1, line1.length() - 2);
        string locked = line2.substr(1, line2.length() - 2);
        cout << "s: " << s << " locked: " << locked << endl;
        if (canBeValid(s, locked)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}

bool canBeValid(string& s, string& locked) {
    int n = s.length();
    if (n % 2 != 0) {
        return false;
    } 
    int unlocked = 0;
    int unbalanced = 0;
    // with each iteration and new index, you either 1) identify a wildcard 2) identify an unbalance 3) remove an imbalance either by identifying a valid or 'spending' wildcard
    // or 4) identify that there's no way balance the string up to that point
    for (int i = 0; i < n; i++) {
        if (locked[i] == '0') {
            unlocked++;
        } else if (s[i] == '(') {
            unbalanced++;
        } else if (s[i] == ')') {
            if (unbalanced > 0) {
                unbalanced--;
            } else if (unlocked > 0) {
                unlocked--; // changes a wildcard earlier in the string to '('
            } else {
                return false; // suppose the wildcard representation was '000' and you encountered a '))' on index 2, no way to salvage
            }
        }
    }
    // in the reverse direction, spend your unlocked on balancing a 
    int balance = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (locked[i] == '0') {
            unlocked--;
            unbalanced--;
        } else if (s[i] == '(') { // not what you want to see early going back.
            balance++;
            unbalanced--;
        } else if (s[i] == ')') {
            balance--;
        }
        if (balance > 0) {
            return false;
        }
        if (balance == 0 && unbalanced == 0) {
            break;
        }
    }
    if (unbalanced > 0) {
        return false;
    }
    return true;
}

/*
So this problem is similar to minimum adds to make parentheses valid. The unlocked characters are wild cards for changes, meaning you can do a pass only
considering the locked characters. The logic is similar for right braces to the other problem, essentially if there's a left inbalance then you're canceling
it out. but if there's no left inbalance (LB == 0), then a right brace is adding to your inbalance total. For the second pass, you 'spend' your unlocked to
try and identify '(' which add to your balance total.
*/
