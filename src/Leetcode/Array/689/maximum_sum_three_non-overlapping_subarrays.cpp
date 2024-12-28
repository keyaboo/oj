#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k);
int main() {
    fast; 
    int t = 2; 
    string line;
    int k;
    while(t--) {
        cin >> line;
        cin >> k;
        string temp;
        stringstream ss(line.substr(1, line.size() - 2));
        vector<int> values;
        while (getline(ss, temp, ',')) {
            values.push_back(stoi(temp));
        }
        vector<int> res = maxSumOfThreeSubarrays(values, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        vector<int> left(n), right(n); // I guess these are for indices?
        vector<int> res(3);
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = nums[i] + prefixSum[i];
        }
        // cout << "prefixSum: " << endl;
        /*
        for (int i = 0; i <= n; i++) {
            cout << prefixSum[i] << " ";
        }
        */
        // cout << "left: " << endl;
        int leftMax = prefixSum[k] - prefixSum[0];
        left[k-1] = 0;
        for (int i=k; i<n; i++) {
            if (prefixSum[i+1] - prefixSum[i+1-k] > leftMax) {
                left[i] = i-k+1;
                leftMax = prefixSum[i+1] - prefixSum[i+1-k];
            } else {
                left[i] = left[i-1];
            }
            // cout << left[i] << " ";
        }
        // cout << endl << "right: " << endl;
        int rightMax = prefixSum[n] - prefixSum[n-k];
        right[n-k] = n-k;
        for (int i = n-k-1; i>=0; i--) {
            if (prefixSum[i+k] - prefixSum[i] >= rightMax) { // gte to ensures lexicographically smaller.
                right[i] = i;
                rightMax = prefixSum[i+k] - prefixSum[i];
            } else {
                right[i] = right[i+1];
            }
            // cout << right[i] << " ";
        }
        int max = 0;
        for (int i = k; i <= n - 2*k; i++) {
            int l = left[i-1];
            int r = right[i+k];
            int total = (prefixSum[l+k] - prefixSum[l]) + (prefixSum[i+k] - prefixSum[i]) + (prefixSum[r+k] - prefixSum[r]);
            if (total > max) {
                max = total;
                res[0] = l;
                res[1] = i;
                res[2] = r;
            }
        }
        return res; 
    }

/*
of length k
it could be a heap? it's going to love {6, 7} and then how do you get out of that situation.
you could have a set to hold onto everything and when you poll, you erase members of the set
with values idx - k.

what it'd look like in java:
filled with int[2]'s : [subarraySum, index]
PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a, b) -> {if (a[0] != b[0] {return a[0] > b[0]} else {return a[1] > b[1]})})

but that's not enough you'd need to explore possibilities where {6, 7} are included or not included.
so like coin change II, except idk how to do that iteratively and compare the {6,7} and 2x {1,2} to the real answer.

no use dynamic programming 1D.

so this wouldn't work for > 3 subarrays, the approach uses "best index" arrays to store info for 1, 2 and 3 subarrays.
so you have a prefix sum array that both "best up until and including now" for indices use.
*/