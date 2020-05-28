#include<bits/stdc++.h>

using namespace std;

int n;
int total[1005], invalid[1005];

int bad(int n) {
    
    // base case
    if (n == 1)
        return invalid[n] = 2;
    
    if (n == 2)
        return invalid[n] = 2 * 2;
    
    if (n == 3)
        return invalid[n] = 2 * 2 * 2 - 1;

    // memo
    if(invalid[n]) 
        return invalid[n];
    
    // recurrence
    // L + dp(n-1)
    // UL + dp(n-2)
    // UUL + dp(n-3)
    // this will make sure there is not 3 consecutive U
    return invalid[n] = bad(n - 1) + bad(n - 2) + bad(n - 3);
}

void good(int n) {
    total[0] = 1;
    for(int i = 1; i <= n; i++) {
        total[i] = total[i - 1] * 2;
    }
}

int main() {
    // freopen("output.txt", "w", stdout);
    good(1000);
    bad(1000);
    while(scanf("%d", &n), n) {
        printf("%d\n", total[n] - invalid[n]);
    }

    return 0;
}
