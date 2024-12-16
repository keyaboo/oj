#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
double maxAverageRatio(vector<vector<int>>& classes, int extraStudents);

int main() {
    fast; 
    int t; 
    cin >> t; 

    while(t--) {
        int numPairs;
        cin >> numPairs;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the newline

        vector<vector<int>> classes;
        for (int i = 0; i < numPairs; i++) {
            string line;
            getline(cin, line); 
            vector<int> classPair;
            stringstream ss(line);
            int num;
            while (ss >> num) {
                classPair.push_back(num);
            }
            classes.push_back(classPair);
        }

        int extraStudents;
        cin >> extraStudents;
        cin.ignore(); // Ignore the newline
        double res = maxAverageRatio(classes, extraStudents);
        cout << res << endl;
    }

    return 0;
}


double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
        double aratio = (double)a.first / a.second;
        double bratio = (double)b.first / b.second;
        double newa = (double)(a.first + 1) / (a.second + 1);
        double newb = (double)(b.first + 1) / (b.second + 1);
        return (newa - aratio) < (newb - bratio);  // To prioritize pairs with higher improvement
    };
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
      // lambdas don't have types, and this is where 'pq' identifier shows up
    for (auto& classPair : classes) {
        pair<int, int> clasz = make_pair(classPair[0], classPair[1]);
        pq.push(clasz);
    }

    while (extraStudents > 0) {
        pair<int, int> topClass = pq.top();
        pq.pop();
        topClass.first++;
        topClass.second++;
        pq.push(topClass); 
        extraStudents--;
    }
    double res = 0;
    while (!pq.empty()) {
        pair<int, int> clasz = pq.top();
        pq.pop();
        res += (double)clasz.first / clasz.second;
    }

    return res / classes.size();

}

/*
sort the classes by denominator. not sure how to do this in C++ but in java it'd
be sort(classes, Comparator.comparingInt(a -> a[2])).
PriorityQueue<int[]> pq = new PriorityQueue<>((a,b) -> {...})

(a, b) -> {(
    double aratio = (double)a[0] / a[1];
    double bratio = (double)b[0] / b[1];
    double newa = (double)(a[0] + 1) / (a[1] + 1);
    double newb = (double)(b[0] + 1) / (b[1] + 1);
    return (newa - aratio) < (newb - bratio);
)}

because you'd need to have some sort of way to sort the best candidates for addition.

the faster solutions just use a helper function for the maxheap and declare it this way:
priority_queue<pair<double, pair<int, int>>> maxHeap;

compared to java, C++ priorityqueues are more complex, they need a container (the second vector thing)
if you're going to bring in a lambda special sorting function.
*/

