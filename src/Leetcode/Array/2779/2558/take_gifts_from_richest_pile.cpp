#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
static long long pickGifts(vector<int>& gifts, int k);

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

        long long res = pickGifts(arr, k);
        cout << res << endl;
    }
    return 0;
}

/*
so sort, take the last element. floor square root it, subtract from total.
calling sort for each k is the brute force which they do accept. that might
be a terrible quicksort configuration though, maybe speed up with manual
swaps. the faster solution uses a priority queue, maybe I'll redo.
*/

static long long pickGifts(vector<int>& gifts, int k) {
        int len = gifts.size();
        sort(gifts.begin(), gifts.end());
        for (int i = 0; i < k; i++) {
            int last = gifts[len - 1];
            int replace = floor(sqrt(last));
            gifts[len - 1] = replace;
            int idx = len - 1;
            while (idx > 0 && gifts[idx] < gifts[idx-1]) {
                swap(gifts[idx], gifts[idx-1]);
                idx--;
            }
        }
        long long sum = 0;
        for (int i = 0; i < len; i++) {
            sum += gifts[i];
        }
        return sum;
    }
