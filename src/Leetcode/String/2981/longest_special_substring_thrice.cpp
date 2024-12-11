#include <bits/stdc++.h> 
#include <string>
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
/*
given a string s. returning length of longest special substring which occurs at least three times.
things that would be important to avoid: most frequent character.
"aaaaxyzaaa" needs to pick up 3. need to confirm that at least one of the characters appears > 2 times.
contiguous 4 means at least 2. I think, determine the length of the current contiguous section. have
a freqs map for different versions of the string. when you have a contiguous region, increment count for
"aaa", "aa", and "a". I think you check to see which characters got at least 3 and keep checking whether
the bigger strings got >= 3.
you don't actually need the char counts array. the key, value are in a pair which is nice.
*/

class Solution {
public:
    int maximumLength(string s) {
        // array<char, 26> counts;
        unordered_map<string, int> freqs;
        int contiguous = 1;
        char prev = s[0];
        // counts[prev - 'a']++;
        freqs[string(1, prev)]++;
        for (int i = 1; i < s.length(); i++) {
            char current = s[i];
            // counts[current - 'a']++;
            if (current == prev) {
                contiguous++;
            } else {
                contiguous = 1;
            }
            for (int len = 1; len <= contiguous; len++) {
                // cout << "len " << len << (i - len + 1) << endl; 
                freqs[s.substr(i - len + 1, len)]++;
            }
            prev = current;
        }
        int maxLen = 0;
        for (const auto& pair : freqs) {
            if (pair.second >= 3) {
                maxLen = max(maxLen, (int)pair.first.length());
            }
        }
        return (maxLen > 0) ? maxLen : -1;
    }
};



int main() {
    fast; 
    string line;
    Solution sol;
    while(getline(cin, line)) {
        string s = line.substr(1, line.length() - 2);
        // cout << s << endl;
        int res = sol.maximumLength(s);
        cout << res << endl; 
    }
    return 0;
}
