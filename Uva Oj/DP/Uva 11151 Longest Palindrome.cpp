#include <bits/stdc++.h>
using namespace std;
// for ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FILEIN freopen("input.txt","r",stdin)
#define FILEOUT freopen("output.txt","w",stdout)
#define DEBUG printf("Works\n")
#define ll long long
#define EPS (1e-8)
#define INF 1000000000
#define mod 1000000007LL
#define maxn 500005
#define pii pair<int, int>

int T;
char str[1005];
int dp[1005][1005];

// longest palindromic subsequence
int solve(int l, int r) {
    // odd basecase
    if (l == r) 
        return 1;
    if ( l + 1 == r)
        // even basecase
        if (str[l] == str[r])
            return 2;
        // remove any  one
        else 
            return 1;

    // dp
    if (dp[l][r] != -1)
        return dp[l][r];
    
    // recursion
    if (str[l] == str[r]) 
        return dp[l][r] = 2 + solve(l + 1, r - 1);
    else
        return dp[l][r] = max(solve(l + 1, r), solve(l, r - 1));
        // exclude left or exclude right

}


int main() {
	scanf("%d", &T);
	getc(stdin);

	while (T--) {
		gets(str);

		if (strlen(str) == 0) {
			printf("0\n");
			continue;
		}

		memset(dp, -1, sizeof(dp));
		int ans = solve(0, strlen(str) - 1);

		printf("%d\n", ans);
	}
