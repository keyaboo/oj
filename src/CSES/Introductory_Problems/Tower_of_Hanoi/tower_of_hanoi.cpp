#include <bits/stdc++.h> 
using namespace std;

#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
void solve(int n, char source, char destination, char auxiliary);
int main() {
    fast; 
    int n; 
    cin >> n; 
    int moves = (1 << n) - 1;
    cout << moves << endl;
    solve(n, '1', '3', '2');
    return 0;
}


void solve(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        cout << source << " " << destination << endl;
        return;
    }
    solve(n - 1, source, auxiliary, destination);
    cout << source << " " << destination << endl;
    solve(n - 1, auxiliary, destination, source);
}

/*
so in order to get the bottom to the right side, everything from 1 has to be loaded onto 2.
3 distinct stacks maybe? oh just looked at the picture you can go from 1 -> 3 directly.

while ring3.size < n;

things you'd have to know: which stack has the largest element, and which stack has the smallest
element.


for even n, 1->S2 for odd n, 1->S3
if all three are filled and both 1 and 2 are on different platforms, 1->2. 
actually that extends to any situation as long as you're undoing the previous move,
second highest appearing goes to highest appearing.

formal language and understanding of recursion was a bit lacking to be able to do this.

characterize base case: if n is 1 move it from the source to the destination peg.

characterize the subproblem: the top disks, and there are n-1 of them, you can just think
of them as a single unit.

Then the largest disk (n==1) gets moved to the destination.

afterward, move the disks (n-1) of them from the auxiliary peg to the destination peg.

I didn't quite figure out how to characterize the subproblems, but this is a good example of
a problem where you can start small, imagine one step, and decide based on the desired
outcome of that step in the context of the larger goal.

forward thinking (imagine next step) and backward reasoning (considering the end goal)

for this problem specifically, you have to clear the path in order for ring 0 to move to dest.
the only configuration for which that can happen is 1 on P1, 1-(n-1) on P2, and empty P3.
*/