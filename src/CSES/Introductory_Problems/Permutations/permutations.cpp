#include <bits/stdc++.h> 
#include <string>
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

/*
consider scrunched up together numbers with this kind of problem.
*/
int main() {
    fast; 
    int n; 
    cin >> n;
    const string nosol = "NO SOLUTION";
    if (n == 1) {
        cout << "1" << endl;
        return 0;
    } else if (n <= 3) {
        cout << nosol << endl;
        return 0;
    }
    int maxOdd = ((n & 1) == 1) ? n : n - 1;
    int maxEven = ((n % 2) == 0) ? n : n - 1;
    for (int i = 2; i <= maxEven; i = i + 2) {
        cout << i << " ";
    }

    for (int i = 1; i <= maxOdd; i = i + 2) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
