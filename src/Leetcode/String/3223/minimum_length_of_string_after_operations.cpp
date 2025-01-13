#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int minimumLength(string& s);

int main() {
    fast; 
    int t = 2;
    string line;
    while(t--) {
        getline(cin, line);
        string str = line.substr(1, line.length() - 2);
        cout << " str: " << str << endl;
        int res = minimumLength(str);
        cout << res << endl;
    }

    return 0;
}

    int minimumLength(string& s) {
        int n = s.length();
        vector<int> counts(26, 0);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            counts[c]++;
        }
        int ops = 0;
        for (int i = 0; i < 26; i++) {
            if (counts[i] == 0) continue;
            ops += (counts[i] % 2 == 1) ? counts[i] - 1 : counts[i] - 2;
        }
        return n - (ops);
    }

/*
so an operation needs to have at least 3 of the same character.
the answer is going to be s.length() minus 2 * ops. ok actually you can just do counts / 3.
no it isn't counts / 3, more sophisticated than that.

        for(int i=0;i<26;i++){
            while(freq[i]>=3){
                freq[i]-=2;
            }
            ans+=freq[i];
        }

this is faster.
*/