#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

/*
2 definitely come from the 10 and the 20.
napkin math the other two come from the 5 and the 15.
there's more to it than that. I don't know whether I'm
undercounting, but it's possible that 25 and 125 also give
it extra zeroes. 
that's what it was.

*/
int main() {
    fast; 
    int n; 
    cin >> n; 
    int quotient = 0;
    for (int i = 1; pow(5,i) < (int)(1e9 + 7); i++) {
        quotient += (n / pow(5,i));
    }
    cout << quotient << endl;
    return 0;
}
