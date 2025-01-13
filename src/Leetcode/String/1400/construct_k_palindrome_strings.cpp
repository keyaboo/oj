#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
bool canConstruct(string& s, int k);
int main() {
    fast; 
    int t = 3;
    string line;
    int num;
    while(t--) {
        getline(cin, line);
        string str = line.substr(1, line.length() - 2);
        cin >> num;
        cin.ignore();
        cout << "num: " << num << " str: " << str << endl;
        if (canConstruct(str, num)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}

bool canConstruct(string& s, int k) {
    if (k > s.length()) {
        return false;
    }
    vector<int> counts(26, 0);
    for (int i = 0; i < s.length(); i++) {
        int c = s[i] - 'a';
        counts[c]++;
    }
    int odds = 0;
    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] % 2 == 1) {
            odds++;
        }
    }
    return (odds <= k);
}

/*
have a freqs map, find count of odd counts of characters, then loop over those counts and see whether the sum exceeds k I guess.

*/
