#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
set<string> solve(string S);
bool nextPermutation(string& str);

int main() {
    fast; 
    string letters; 
    getline(cin, letters);
    sort(letters.begin(), letters.end());
    set<string> unique = solve(letters);    
    cout << unique.size() << endl;
    for (string permutation : unique) {
        cout << permutation << endl;
    }
    return 0;
}

set<string> solve(string s) {
    int n = s.length();
    sort(s.begin(), s.end());
    set<string> unique;
    do {
        unique.insert(s);
    } while (nextPermutation(s));
    return unique;
}

/*
bitmask problem?
might be a good opportunity to use multisets again. then they get printed
in lexicographically larger values.

divide and conquer, but this isn't a generate combinations problem like 2035 was.
the answer is n!

abc
acb
bac
bca
cab
cba

yeah just use a bitmask to create the permutations. - no. that's for combinations.

*/


/*
stl implementation is nice but actually seeing what's going on with this. takes a sorted
array in a presumably lower lexicographical arrangement. 

oh this is the same thing as the next permutation problem except it's pass by reference 
and returns a bool.
*/
bool nextPermutation(string& str) {
    int n = str.size();

    // here's the pivot
    int i = n - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }

    if (i < 0) {
        reverse(str.begin(), str.end());
        return false;
    }
    // here's the candidate
    int j = n - 1;
    while (str[i] >= str[j]) {
        j--;
    }
    // do the swap
    swap(str[i], str[j]);
    // reverse from the point of pivot + 1 to end
    reverse(str.begin() + i + 1, str.end());
    return true;
}