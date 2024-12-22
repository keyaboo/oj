#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

vector<bool> solve(string s, vector<pair<int, int>> queries) {
    if (s.length() < 4) {
        return vector<bool>(queries.size(), false);
    }
    vector<bool> res;
    set<int> hits;

    for (int i = 0; i < s.length() - 3; i++) {
        int miss = 0;
        
    if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') {
            hits.insert(i);
        }
    }

    for (const auto& query : queries) {
        int idx = query.first - 1;
        char change = query.second ? '1' : '0';
        s[idx] = change; 

        for (int i = max(0, idx - 3); i <= min(int(s.length()) - 4, idx); i++) {
            if (s[i] == '1' && s[i+1] == '1' && s[i+2] == '0' && s[i+3] == '0') {
                    hits.insert(i);
                } else {
                    hits.erase(i); // you can erase stuff that isn't there.
                }
        }
        res.push_back(!hits.empty());
    }

    return res;
}

int main() {
    fast; 
    int t; 
    cin >> t; 
    string s;
    cin.ignore();

    while(t--) {
        getline(cin, s);
        // cout << s << endl;
        int q;
        cin >> q;
        vector<pair<int, int>> queries;
        int qi, v1;
        for (int i = 0; i < q; i++) {
            cin >> qi >> v1;
            queries.push_back({qi, v1});
            // cout << " qi " << qi << " q " << v1;
        }
        cin.ignore();
        vector<bool> res = solve(s, queries);
        for (int i = 0; i < res.size(); i++) {
            string ans = (res[i]) ? "YES" : "NO";
            cout << ans << endl;
        }
    }

    return 0;
}

/*
there's just no getting around the fact that you have to do the comparison at most 4 times.
        for (int i = max(0, idx - 3); i <= min(int(s.length()) - 4, idx); i++) {
this loop is probably the trickiest part of this problem esp on the high end.

*/
