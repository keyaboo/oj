#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
vector<int> finalPrices(vector<int>& prices);

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
        vector<int> res = finalPrices(arr);
        for (int i : res) cout << i << " ";
        cout << endl;
    }

    return 0;
}

vector<int> finalPrices(vector<int>& prices) {
    for (int i = 0; i < prices.size(); i++) {
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[j] <= prices[i]) {
                prices[i] -= prices[j];
                break;
            }
        }
    }
    return prices;
}

/*
it's the first j, ok. this problem was so easy that it's upsetting I had to change a
lt to lte and so not completely flawless from inception.
*/