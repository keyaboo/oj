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
        // cout << tree1 << endl;
        vector<vector<int>> edges1 = parse2DArray(tree1);
        vector<vector<int>> edges2 = parse2DArray(tree2);
        int res = minimumDiameterAfterMerge(edges1, edges2);
        cout << res << endl;
    }
    return 0;
}

int modifiedKahn(vector<vector<int>>& edges) {
    const int numNodes = edges.size() + 1;
    vector<int> degree(numNodes, 0); 
    vector<vector<int>> adjacencyList(numNodes);
    // [[0,1],[0,2],[0,3]]
    for (auto& edge : edges) {
        int node1 = edge[0], node2 = edge[1];
        adjacencyList[node1].push_back(node2);
        adjacencyList[node2].push_back(node1);
        degree[node1]++; 
        degree[node2]++;
    }
    // adjacencyList = [[1, 2, 3], [0], [0], [0]]
    int queue[numNodes];
    int front = 0, back = 0;
    for (int i = 0; i < numNodes; i++) {
        if (degree[i] == 1) { 
            queue[back++] = i;
        }
    }
    // [1, 2, 3] front is 0 back is 3

    int level = 0, remainingNodes = numNodes;
    // remaining nodes = 4
    while (remainingNodes > 2) { 
        int queueSize = back - front;
        remainingNodes -= queueSize;
        level++; 
        // this is a level-by-level processing just like bounding for loop with queue size for the swaps problem.
        for (int i = 0; i < queueSize; i++) {
            int currentNode = queue[front++];
            for (int neighbor : adjacencyList[currentNode]) {
                if (--degree[neighbor] == 1) { // adds leaf nodes to queue where degree == 1
                    queue[back++] = neighbor;
                }
            }
        }
    }

    return (remainingNodes == 2) ? 2 * level + 1 : 2 * level;
}

int minimumDiameterAfterMerge(vector<vector<int>>& edges1, 
                                 vector<vector<int>>& edges2) {
    int diameter1 = modifiedKahn(edges1); 
    int diameter2 = modifiedKahn(edges2); 
    return max({diameter1, diameter2, (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1});
}

/*
Perhaps there's some way of finding out what the most central nodes of each tree are. find
lengths for each node, the "operation" in a symmetric situation probably doesn't care which
one is chosen. can probably have two maps, key is nodeval : val is a list of outdegree nodes.
I guess you could either have a queue for bfs or faster traversal with dfs.

that didn't really work, also had a bad assumption about the return being a sum of the two
when T1 could be the only determining factor.

Kahn's algorithm and topological sorting, haven't seen that in a while.

this works by identifying all leaf nodes in the tree, or those that have degree 1.
The pruning process continues by-level until 2 or fewer nodes remain. As you work inward,
you'll find out whether there's a central node or two central nodes (symmetry thing I thought about earlier)
depending on the quantity of remaining nodes.
For this problem, since it's an undirected graph there's no distinction b.w. in/out-degree.
*/