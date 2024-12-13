#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

/*
could just have an int[26] array that gets loaded up. odd length strings can have one odd
count appearance.
*/

int main() {
    fast;
    string line; 
    getline(cin, line);
    vector<int> counts(26,0);
    for (int i = 0; i < line.size(); i++) {
        int c = line[i] - 'A';
        counts[c]++;
    }
    int idx = 0;
    int mid = -1;
    char res[line.size() + 1];
    res[line.size()] = '\0';
    for (int i = 0; i < 26; i++) {
        int count = counts[i];
        while (count > 0) {
            if (count == 1) {
                if (mid != -1) {
                    cout << "NO SOLUTION" << endl;
                    return 0;
                } else {
                    mid = i;
                }
            }
            res[idx] = i + 'A';
            res[line.size() - idx] = i + 'A';
            idx++;
            count -= 2;
        }
    }
    if (mid != -1) {
        res[idx] = mid + 'A';
    }
    string s(res);
    cout << s << endl;
    return 0;
}
