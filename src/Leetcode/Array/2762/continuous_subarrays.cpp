#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
long long continuousSubarrays(vector<int>& nums);

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

        long long res = continuousSubarrays(arr);
        cout << res << endl;
    }
    return 0;
}


long long continuousSubarrays(vector<int>& nums) {
    long long count = 0;
    multiset<int> st;
    int slow = 0;
    for (int i = 0; i < nums.size(); i++) {
        st.insert(nums[i]);
        while (st.size() > 1 && *st.rbegin() - *st.begin() > 2) {
            st.erase(st.find(nums[slow]));
            slow++;
        }
        count += i - slow + 1;
    }   
    return count;
}

/*
could it really be as simple as take the differnces and then fast & slow pointer? is everyone
just getting the counting wrong. it's not as easy as that unfortunately.

multisets store elements in sorted order.

{1, 4, 2, 5}

window: [1]
st: {1}

window: [1,4]
st {1,4} -> 4-1 gt 2 so st {4}

window [4, 2]
st {2, 4}

i = 3
window [4, 2, 5]
st {2, 4, 5} -> 5-2 gt 2 so st {4, 5}
*/