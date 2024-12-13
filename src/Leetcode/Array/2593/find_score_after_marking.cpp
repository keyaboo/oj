#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
long long findScore(vector<int>& nums);

int main() {
    fast; 
    string line;
    // cin.ignore();

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

        long long res = findScore(arr);
        cout << res << endl;
    }
    return 0;
}
/*
what I would think is have a hashset, fill it up with indices and their +-1.
first test case isn't picking up the 4 for some reason.
oh I thought I could be liberal with adding extra indices but that's not a good
idea. 
it can be the first appearance means loop in the regular order.


*/
long long findScore(vector<int>& nums) {
    long long score = 0;
    int n = nums.size();
    unordered_set<int> indices;
    while (indices.size() < nums.size()) {
        int startidx = nums.size() - 1;
        while (indices.count(startidx) > 0) {
            startidx--;
        }
        int minValue = nums[startidx];
        int minIndex = startidx;
        for (int i = startidx; i >= 0 && (indices.count(i) == 0); i--) {
            if (nums[i] <= minValue) {
                minValue = nums[i]; 
                minIndex = i;
            }
        }
        score += minValue;
        indices.insert(minIndex);
        if (minIndex > 0 && indices.count(minIndex - 1) == 0) {
            indices.insert(minIndex - 1);
        }
        if (minIndex < n - 1 && indices.count(minIndex + 1) == 0) {
            indices.insert(minIndex + 1);
        }
    }
    return score;
}
