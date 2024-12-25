#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2);

std::vector<std::vector<int>> parse2DArray(const std::string& input) {
    std::vector<std::vector<int>> result;
    std::vector<int> currentVector;
    int number;
    char separator; 

    std::stringstream ss(input);

    ss.ignore(2); 
    // ignore the two leading '[' characters
    while (ss) {
        ss >> number >> separator; 
        if (!ss) break; 
        // cout << "number " << number << endl;
        currentVector.push_back(number);

        ss >> number >> separator;
        if (!ss) break; 

        currentVector.push_back(number); 
        result.push_back(currentVector);
        currentVector.clear();

        ss.ignore(); 
        if (ss.peek() == ',') {
            ss.ignore();
        }
        if (ss.peek() == '[') {
            ss.ignore();
        }
    }

    return result;
}


int main() {
    fast; 
    int t = 2; 
    string tree1;
    string tree2;
    while(t--) {
        getline(cin, tree1);
        getline(cin, tree2);
        cout << tree1 << endl;
        vector<vector<int>> edges1 = parse2DArray(tree1);
        vector<vector<int>> edges2 = parse2DArray(tree2);
        int res = minimumDiameterAfterMerge(edges1, edges2);
        cout << res << endl;
    }
    return 0;
}


int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    return 0;        
}
