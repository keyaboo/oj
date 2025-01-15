#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B);

int main() {
    fast; 
    int t = 2;
    while(t--) {
        string line1, line2;
        getline(cin, line1);
        getline(cin, line2);

        vector<int> arr1, arr2;

        // Process the first line
        if (line1.size() >= 2 && line1[0] == '[' && line1.back() == ']') {
            line1 = line1.substr(1, line1.size() - 2);
            istringstream iss1(line1);
            int num;
            char separator;
            while (iss1 >> num) {
                arr1.push_back(num);
                if (!(iss1 >> separator)) break;
            }
        } else {
            cerr << "Invalid input format for the first array." << endl;
            continue; // Skip to the next test case
        }

        // Process the second line
        if (line2.size() >= 2 && line2[0] == '[' && line2.back() == ']') {
            line2 = line2.substr(1, line2.size() - 2);
            istringstream iss2(line2);
            int num;
            char separator;
            while (iss2 >> num) {
                arr2.push_back(num);
                if (!(iss2 >> separator)) break;
            }
        } else {
            cerr << "Invalid input format for the second array." << endl;
            continue; // Skip to the next test case
        }
        vector<int> res = findThePrefixCommonArray(arr1, arr2);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<int> res(n, 0);
    unordered_set<int> aVals, bVals;
    int count = 0;
    for (int i = 0; i < n; i++) {
        aVals.insert(A[i]);
        bVals.insert(B[i]);
        if (A[i] != B[i]) {
        if (bVals.count(A[i])) count++;
        if (aVals.count(B[i])) count++;
        } else {
            count++;
        }
        res[i] = count;
    }
    return res;
}

/*
ok just having two sets leads to an overcounting problem, no it doesn't I just needed to account for the vals of A and B being the same
at index i.
the fastest solution has like, a single shared freqs array that if it reaches two you increment counts.
*/