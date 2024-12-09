#include <bits/stdc++.h> 
#include <string>
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    string input; 
    getline(cin, input);
    char c = input[0];
    size_t maxLen = 0;
    size_t idx = 0;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] != c) {
            c = input[i];
            idx = i;
        } else {
            maxLen = max(maxLen, i - idx + 1);
        }
    }
    cout << maxLen << endl;
    return 0;
}
