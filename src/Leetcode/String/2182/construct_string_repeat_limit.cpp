#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
string repeatLimitedString(string s, int repeatLimit);

int main() {
    fast; 
    int t = 2;
    string line;
    int num;
    while(t--) {
        getline(cin, line);
        string str = line.substr(1, line.length() - 2);
        cin >> num;
        cin.ignore();
        // cout << "num: " << num << endl;
        string res = repeatLimitedString(str, num);
        cout << res << endl;
    }

    return 0;
}

    string repeatLimitedString(string s, int repeatLimit) {
        priority_queue<pair<char, int>> maxheap;

        map<int, int> freqs;
        for (int i = 0; i < s.length(); i++) {
            freqs[s[i] - 'a']++;    
        }
        for (int i = 0; i < freqs.size(); i++) {
            if (freqs[i] > 0) {
                char key = i + 'a';
                maxheap.push({key, freqs[i]});
                // cout << key << ": " << freqs[i] << endl;
            }
        }
        string res = "";
        while (!maxheap.empty()) {
            pair<char, int> letter = maxheap.top();
            maxheap.pop();
            int count = 0;
            while (letter.second > 0 && count < repeatLimit) { // and
                res += letter.first;
                letter.second--;
                count++;
            }
            if (!maxheap.empty() && letter.second > 0) {
                pair<char, int> nextletter = maxheap.top();
                maxheap.pop();
                res += nextletter.first;
                nextletter.second--;
                maxheap.push(letter);
                if (nextletter.second > 0) maxheap.push(nextletter);
            }
        }
        return res;
    }

/*
lexicographically largest string possible. this has a very high acceptance rate.
it's another priority queue problem, I didn't want it to be but the hint was in the
repeat limit sort of, any other kind of loop just doesn't really handle that too well.
by default, for pairs, std::less is the comparison function used.

priority_queue<Type, Container, Comparator> so unless you need to overload different
template parameters the container and comparator can be neglected.
*/