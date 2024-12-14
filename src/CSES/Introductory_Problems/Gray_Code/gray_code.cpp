#include <bits/stdc++.h> 
#include <bitset>

using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
void alternate(int n);
void flipidx(string& binary, int idx);
/*
there's probably some symmetry trick here. nah probably a dp table with
size n^2, maybe n + 1 squared. 1 - arr[i] flips 0/1. no dp table actually.
in java it would be system.arraycopy.

no that's dumb just build a new string and then do the flips.
I didn't notice the string full of 1's not making it.

it doesn't like the order I did this in even though it's right.

000 2 flip n - 1
001 1 flip n - 2
011 2 flip n - 1
010 0 flip n - 2
110 0 flip n - 3
111 2 flip n - 1
101 1 flip n - 2
100 0 flip n - 3


I wasn't going to get the answer to this without looking up how to do bit stuff.
easier to think of this as i from 0 to 8. the graycode is the bitwise xor of that
number.

eg i = 4 is represented as 100
i >> 1 shifts everything to the right 010
the bitwise xor
100
010
---
110 because all those bits are different.
*/
int main() {
    fast; 
    int n; 
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        int graycode = i ^ (i >> 1); // thing in parens shifts the bits of binary number i one position to the right. it drops rightmost bit.
        bitset<32> binary(graycode);
        string graycodestring = binary.to_string().substr(32 - n);
        cout << graycodestring << endl;
    }
       return 0;
    }

void flipidx(string& binary, int idx) {
    int c = binary[idx] - '0';
    binary[idx] = (1 - c) + '0';
}

/*
void alternate(int n) {
        for (int i = 0; i < n; i++) {
        string binary;
        for (int k = i; k < n ; k++) {
            binary.append("0");
        }
        for (int j = 0; j < i; j++) {
            binary.append("1");
        }

        cout << binary << endl;
        for (int idx = n-1; idx > i; idx--) {
            int c = binary[idx] - '0';
            binary[idx] = (1 - c) + '0';
            cout << binary << endl;
        }
    }
    string binary;
    for (int j = 0; j < n; j++) {
        binary.append("1");
    }
    cout << binary << endl;
}
*/