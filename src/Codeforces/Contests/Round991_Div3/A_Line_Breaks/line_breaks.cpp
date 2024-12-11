#include <bits/stdc++.h> 
#include <string>
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
/*
can't think of any edge cases here.
*/

int main() {
    fast; 
    int t; 
    cin >> t; 
    // printf("%d\n", t);
    while(t--) {
        int n, m;
        cin >> n >> m;
        cin.ignore();
        vector<string> words;
        string word;
        int count = 0;
        for (int i = 0; i < n; i++) {
            getline(cin, word);
            words.push_back(word);
            // printf("Word %d: %s\n", i + 1, word.c_str());
            m -= (word.length());
            if (m >= 0) { count++; } 
        }
        cout << count << endl;
    }

    return 0;
}
