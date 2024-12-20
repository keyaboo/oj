#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
vector<int> getFinalState(vector<int>& nums, int k, int multiplier);
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

        int k, multiplier;
        cin >> k; 
        cin >> multiplier;
        cin.ignore();
        cout << "k " << k << " multiplier " << multiplier << endl;
        vector<int> res = getFinalState(arr, k, multiplier);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*
the brute force for this one is straightforward enough but I think the TLE might be baked in there.
maybe have a treeset of intervals for [num, multiplier * num] and a hashmap to keep track of the
index of where that was seen. oh I'm overcomplicating this like crazy it's a min heap. keeping track
of how to decrement k when there could be multiple indexes would be a chore but not so with a priority
queue. going to use AI for the comparator function, again in java this would be something like
(a, b) -> {if (a[0] != b[0] {return a[0] - b[0]} else {return a[1] - b[1]})}. maximum pass ratio had
an example nevermind.
*/
vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) { return a.first > b.first; } else { return a.second > b.second; }
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);

    for (int i = 0; i < nums.size(); i++) {
        pq.push({nums[i], i});
    }
    
    while (k > 0) {
        pair<int, int> smallest = pq.top();
        pq.pop();
        nums[smallest.second] *= multiplier;
        pq.push({nums[smallest.second], smallest.second});
        k--;
    }
    return nums;
}