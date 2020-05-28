#include<bits/stdc++.h>

using namespace std;

int T, n, cases;
int mod = 10056;
int dp[1005];
int binom[1005][1005];


// memoizing the binomial coficients till 1000C1000
void binomial() {

    for (int n = 1; n <= 1002; n ++) {
        for (int k = 0; k <= 1002; k ++) {
            if (n < k) 
                binom[n][k] = 0;
            else if (n == k || k == 0)
                binom[n][k] = 1;
            else 
                binom[n][k] = (binom[n - 1][k - 1] + binom[n -1][k]) % mod;
        }
    }

}

int solve(int horses) {
    // base
    if (horses == 0)
        return dp[horses] = 1;

    // memo
    if (dp[horses]) 
        return dp[horses];

    // reccurence
    int ret = 0;
    for (int first = 1; first <= horses; first ++) {
        /// first amount of horses gets first and rest becomes second
        /// for the rest of the horses we can repeat the process
        ret += ( binom[horses][first] * solve(horses - first) ) % mod;
        ret %= mod;
    }
    
    return dp[horses] = ret;
}


int main() {
    // freopen("output.txt", "w", stdout);
    scanf("%d", &T);

    binomial();
    solve(1002);
    

    while(cases < T) {
        scanf("%d", &n);
        printf("Case %d: %d\n", ++cases, dp[n]);
    }
    

    return 0;
}
