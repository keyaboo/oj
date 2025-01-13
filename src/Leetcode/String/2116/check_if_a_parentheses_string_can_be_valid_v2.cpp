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
    if (n % 2 == 1) return false;
    int wildcard, LB, RB = 0;
    for (int i = 0; i < n; i++) {
        if (locked[i] == '0') {
            wildcard++;
        } else if (s[i] == '(') {
            LB++;
        } else if (s[i] == ')') {
            RB++;
        }
        if (wildcard - LB + RB < 0) {
            return false;
        }
    }
    wildcard, LB, RB = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (locked[i] == '0') {
            wildcard++;
        } else if (s[i] == '(') {
            LB++;
        } else if (s[i] == ')') {
            RB++;
        }
        if (wildcard - RB + LB < 0) {
            return false;
        }
    }
    return true;
}

/*
way more intuitive approach. My first thought was that which one was added and which one subtracted would be in reverse.
But for the forward pass, subtracting LB accounts for the fact that the locked open parens contributes to a need for more
closing parentheses to balance. Adding RB accounts for the fact that locked closed parentheses add to a surplus of closing
parentheses. The negative imbalance check basically states, even if you used all of the wildcard parentheses as opening
parentheses, you still wouldn't have enough to balance the existing locked closed parentheses.
*/