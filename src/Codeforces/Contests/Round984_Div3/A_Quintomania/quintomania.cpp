#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

bool solve(vector<int>& notes) {
    if (notes.size() == 1) {
        return false;
    }
    int lead = notes[0];
    for (int i = 1; i < notes.size(); i++) {
        int diff = abs(notes[i] - lead);
        if (!(diff == 5 || diff == 7)) return false;
        lead = notes[i];
    }
    return true;
}

int main() {
    fast; 
    int t; 
    int n;

    cin >> t; 

    while(t--) {
        cin >> n;
        vector<int> notes(n);
        for (int i = 0; i < n; i++) {
            int note;
            cin >> note;
            notes[i] = note;
        }
        string res = (solve(notes)) ? "YES" : "NO";
        cout << res << endl; 
    }

    return 0;
}
