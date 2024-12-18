#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
string repeatLimitedString(string s, int repeatLimit);

int main() {
    fast; 
    int t = 2;
    while(t--) {
        string str;
        int num;
        cin >> str >> num; 
        string res = repeatLimitedString(str, num);
        cout << res << endl;
    }

    return 0;
}

    string repeatLimitedString(string s, int repeatLimit) {
        string res = "";
        map<char, int> freqs;

        auto 
        for (int i = 0; i < s.length(); i++) {
            int freq = 0;
            if (freqs.find(s[i] > 0)) {
                freq = freqs.find(s[i]);
            }
            freqs[s[i]] = freq;
        }
        map<char,int>::iterator it = freqs.end();
        std::cout << "Last element: " << it->first << ": " << it->second << endl;;

        return res;
    }

/*
lexicographically largest string possible. this has a very high acceptance rate.
hashmap is an unordered map usually, perhaps there's an ordered map that we
can return to the maximum or minimum key of. can't believe i've barely touched
treemaps in java.
*/