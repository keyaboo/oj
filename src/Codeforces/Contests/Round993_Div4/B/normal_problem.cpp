#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 

int main() {
    fast; 
    int t; 
    cin >> t; 
    cin.ignore();
    string line;
    while(t--) {
        getline(cin, line);
        reverse(line.begin(), line.end());
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == 'p') {
                line[i] = 'q';
            } else if (line[i] == 'q') {
                line[i] = 'p';
            }
        }
        cout << line << endl;
    }

    return 0;
}
