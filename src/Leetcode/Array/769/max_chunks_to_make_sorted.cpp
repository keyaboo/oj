#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int maxChunksToSorted(vector<int>& arr);
int main() {
    fast; 
    string line;

    while (getline(cin, line)) {
        vector<int> arr;
        line = line.substr(1, line.size() - 2);

        istringstream iss(line);
        int num;
        char separator;
        while (iss >> num) {
            arr.push_back(num);
            iss >> separator;
        }
        int res = maxChunksToSorted(arr);
        cout << res << endl;
    }

    return 0;
}

int maxChunksToSorted(vector<int>& arr) {
    int chunk = 0;
    int indexsum = 0, prefixsum = 0;
    for (int i = 0; i < arr.size(); i++) {
        prefixsum += arr[i];
        indexsum += i;
        if (indexsum == prefixsum) {
            chunk++;
        }
    }
    return chunk;
}

/*
tried all kinds of stuff with this one. one observation is that if a val is greater
than the index, then the appropriate val must be further along in the array. I tried
to do a search for that val in order to repeat the process but it wasn't sensitive
to the possibility that an even bigger number could be in the window.

prefix sum is insensitive to that, unfortunately not something I considered as a possibility.
*/