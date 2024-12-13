#include <bits/stdc++.h> 
using namespace std;
static const int inf = 1e9;
#define endl '\n'
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); 
static int solve(string a, string b, string c);
static int dfs(string a, string b, string c, int n, int m);


int main() {
    fast; 
    int t; 
    cin >> t; 
    cin.ignore();

    while(t--) {
        string a, b, c;
        getline(cin, a);
        getline(cin, b);
        getline(cin, c);

        int res = solve(a, b, c);
        cout << res << endl;
    }

    return 0;
}

/*
just understanding this problem, uhh. oh I see, c is just a composite, a and b both get smaller.
the steps of replacement are distinct from the steps of appending, of which there would be len of c.
the entire string could be fake but looking for first appearance matches from either string seems
sensible. perhaps 3d dp, one dimension would be 2 for a & b strings, another dimension would be
the length of c + 1. I think recursive dfs might be how you set up getting your answer. definitely
some sort of min function with memoization.

probably not going to figure this out in a timely manner will look at the editorial.

ok the table is dp[m][n] where m and n are the lengths of strings a, b. it might not be a boolean
table it might be integer where it would could be max of index of the characters in c.

oh you set up borders, wouldn't have guessed. the value inside is the number of replacement steps.
you don't loop over the string you loop over the dp array and for i,j pairs you add and match a
character in string c.

getting used to these indices being +1 in the dp arrays and necessitating a <= or else everything
gets messed up. also this has a mistake in it somewhere.

adapting this problem to dfs recursion a la coin change II is a bad idea because the change history
would be missing without a 2D table tabulating the minimum number of changes to form the first i+j
characters of c.

framing of the dp subproblem: for each character of the resulting string, what are the fewest
number of changes to characters from string a & b that can make up the string so far.
*/
static int solve(string a, string b, string c) {
    int n = a.length();
    int m = b.length();
    int len = m + n;
    vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i+1][0] = dp[i][0] + (a[i] != c[i]);
    }
    for (int j = 0; j < m; j++) {
        dp[0][j+1] = dp[0][j] + (b[j] != c[j]);
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int above = dp[i-1][j] + (c[i+j - 1] != a[i - 1]);
            int left = dp[i][j-1] + (c[i+j - 1] != b[j - 1]);
            dp[i][j] = min(above, left);

        }
    }
    
    return dp[n][m];
}
