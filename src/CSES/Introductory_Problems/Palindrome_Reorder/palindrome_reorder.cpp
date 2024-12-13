#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

/*
could just have an int[26] array that gets loaded up. odd length strings can have one odd
count appearance. better way to do this is with a stack for the second half I just realized.

want to use longs and not char arrays. string is kind of like a hybrid of java stringbuilder
and string. stacks aren't as convenient.
*/

int main() {
    fast;
    string line; 
    getline(cin, line);
    vector<long> counts(26,0);
    for (int i = 0; i < line.size(); i++) {
        int c = line[i] - 'A';
        counts[c]++;
    }
    int idx = 0;
    int mid = -1;
    string res;
    stack<char> backhalf;
    for (int i = 0; i < 26; i++) {
        long count = counts[i];
        while (count > 0) {
            if (count == 1) {
                if (mid != -1) {
                    cout << "NO SOLUTION" << endl;
                    return 0;
                } else {
                    mid = i;
                    break;
                }
            }
            res += i + 'A';
            backhalf.push(i + 'A');
            count -= 2;
        }
    }
    if (mid != -1) {
        res += mid + 'A';
    }
    while (!backhalf.empty()) {
        res += backhalf.top();
        backhalf.pop();
    }
    string s(res);
    cout << s << endl;
    return 0;
}
