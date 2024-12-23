#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> questions;
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            questions.push_back(a);
        }
        set<int> answers;
        for (int i = 1; i <= n; i++) answers.insert(i);
        for (int i = 0; i < k; i++) {
            int q;
            cin >> q;
            answers.erase(q);
        }
        for (int question : questions) {
            if (answers.size() == 0) {
                cout << "1";
            } else if (answers.size() == 1 && answers.count(question)) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }

    return 0;
}

/*
so the complement of whatever the
*/