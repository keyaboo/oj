#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int minimumDifference(vector<int>& nums);
long long minimumDifferencePiles(vector<int>& nums, int idx, long long sum1, long long sum2);
int main() {
    fast; 
    int n; 
    cin >> n; 

    vector<int> nums;
    while(n--) {
        int a;
        cin >> a;
        nums.push_back(a);
    }
    long long res = minimumDifferencePiles(nums, 0, 0, 0);
    cout << res << endl;
    return 0;
}

long long minimumDifferencePiles(vector<int>& nums, int idx, long long sum1, long long sum2) {
    if (idx == nums.size()) {
        return abs(sum1 - sum2);
    }
    long long select = minimumDifferencePiles(nums, idx+1, sum1 + nums[idx], sum2);

    long long noselect = minimumDifferencePiles(nums, idx+1, sum1, sum2 + nums[idx]);
    return min(select, noselect);
}

/*
ok this is a recursion problem. base case is nums.size() = 1, if you choose one you have to add it to pile1,
if you choose the other you have to add it to pile 2.
*/

int minimumDifference(vector<int>& nums) {
    int n = nums.size(), sum = 0;
    for (int num : nums) sum += num;

    int N = n/2;
    // this isn't generating the permutations only the various possible
    // sums in the left and right part of the array.
    vector<vector<int>> left(N+1), right(N+1);
    for (int mask = 0; mask < (1 << N); mask++) {
        int lsum = 0, rsum = 0, size = 0;
        // if you wanted to get a subset vector out of this, this is where you'd instantiate . thankfully we don't need.
        for (int i = 0; i < N; i++) {
            if (mask &(1 << i)) {
                size++;
                lsum += nums[i];
                rsum += nums[i + N];
            }
        }
        left[size].push_back(lsum);
        right[size].push_back(rsum);
    }

    for (int size=0; size<=N; size++) {
        sort(right[size].begin(), right[size].end());
    }
    // extreme situation where all elements are taken from either the left or right half.
    // res is like a starting point of two impossible (and unlikely to be close to the real answer)
    // configurations. there's only one value at eg left[N][i]
    int res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));
    for (int size = 1; size < N; size++) {
        for (auto &leftsum : left[size]) {
            int rightsumtarget = (sum - 2 * leftsum) / 2;
            int rsz = N - size;
            auto& rightsums = right[rsz];
            // binary search on the rightsums vector to find the first element that is greater than or equal to rightsumtarget
            auto rightitr = lower_bound(rightsums.begin(), rightsums.end(), rightsumtarget);
            if (rightitr != rightsums.end()) 
                res = min(res, abs(sum - 2 * (leftsum + (*rightitr))));
            
            if (rightitr != rightsums.begin()) {
                auto it = rightitr;
                it--;
                res = min(res, abs(sum - 2 * (leftsum + (*it))));
            }
            
        }
    }
    return res;
}


/*
this is meet in the middle where the bitmask stuff actually comes up. 
the same problem as partition array into two to minimize sum difference 2035.

no it isn't.
*/