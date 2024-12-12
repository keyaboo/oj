#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
int maximumBeauty(vector<int>& nums, int k);

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

        int k;
        cin >> k; 
        cin.ignore();

        int res = maximumBeauty(arr, k);
        cout << res << endl;
    }
    return 0;
}

/* any number of times usually means look for a pattern.
the O(n^2) solution is sort of trivial. could this be a treeset problem where you look
for maximal overlap. could just sort and see how long the contiguous chain of nums[i] + k
happens to be, similar to yesterday. oh you could do this as a sliding window instead.
*/

int maximumBeauty(vector<int>& nums, int k) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int maxlen = 0;
    int fastidx = 0;
    int slowidx = 0;
    int contiguous = 1;
    while (fastidx < len) {
        int num = nums[slowidx];
        while (fastidx < nums.size() && nums[fastidx] <= (num + 2*k)) {
        maxlen = max(maxlen, fastidx - slowidx + 1);
        fastidx++;    
        }
        slowidx++;
    }
        return maxlen; 
    }

