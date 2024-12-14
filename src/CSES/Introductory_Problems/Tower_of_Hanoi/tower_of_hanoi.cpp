#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    int n; 
    cin >> n; 
    stack<int> ring1, ring2, ring3;
    for (int i = n; i >= 1; i--) {
        ring1.push(i);
    } 
    cout << ring1.top() << endl;
    return 0;

}

/*
so in order to get the bottom to the right side, everything from 1 has to be loaded onto 2.
3 distinct stacks maybe? oh just looked at the picture you can go from 1 -> 3 directly.

while ring3.size < n;

things you'd have to know: which stack has the largest element, and which stack has the smallest
element.

if there's 2 open rings, move the smallest element to (one of them?) - the second ring.
if there are 0 open rings, move smallest to one with a smaller value TOS.
if there's one open ring, move largest to open ring unless largest is on ring 3.
if three are taken up, move largest (unless largest is on 3) to the ring with the largest
on it.
if three are taken up, smallest is by itself, put it on largest.


*/