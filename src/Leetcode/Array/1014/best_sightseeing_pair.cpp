#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int maxScoreSightseeingPair(vector<int>& values);

int main() {
    fast; 
    int t = 2; 
    string line;
    while(t--) {
        getline(cin, line);
        string temp;
        stringstream ss(line.substr(1, line.size() - 2));
        vector<int> values;
        while (getline(ss, temp, ',')) {
            values.push_back(stoi(temp));
        }
        int res = maxScoreSightseeingPair(values);
        cout << res << endl;
    }
    return 0;
}

int maxScoreSightseeingPair(vector<int>& values) {
    int best = INT_MIN;
    int idx = 0;
    int highest = values[0];
    for (int i = 1; i < values.size(); i++) {
        highest--;
        int distance = i - idx;
        best = max(best, values[idx] + values[i] - distance);
        if (values[i] > highest) {
            idx = i;
            highest = values[i];
        }
    }
    return best;
}

/*
you could have a greedy variable highest like best time to buy & sell stock. as you progress
further along the array that value gets decremented by 1 with each iteration. actually, preserving
index also likely is the play. if the number you're looking at is greater than 
distance(idx, i) * -1 + maxVal, you'd reassign it but do so after a max check for best sightseeing
criteria or w/e.

distance is only for pointers/iterators.

alternative which is clever: break the calculation down into values[i] + i + (values[j] - j)
you initialize the solution to be 0 instead of int min, have a highest variable like I have in mine,
and for each iteration of the loop, decrement the highest, and determine the new best sightseeing
spot with max(best, highest + curr). the net difference of i - j is baked into whatever highest
is at that point of max calculation already (previous and current loop iteration)
*/