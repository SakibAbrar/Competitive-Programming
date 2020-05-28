#include<bits/stdc++.h>

using namespace std;

int n;
int dp[7505];


int main() {
    // freopen("output.txt", "w", stdout);
    int coins[] = {1, 5, 10, 25, 50};
    
    dp[0] = 1;
    for (int i = 0; i < 5; i ++) {
        for (int num = 1; num <= 7500; num++)
            if (num >= coins[i])
                dp[num] += dp[num - coins[i]];
    }
    
    while( scanf("%d", &n) ) {
        printf("%d\n", dp[n]);
    }

    return 0;
}
