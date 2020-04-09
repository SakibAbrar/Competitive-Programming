#include<bits/stdc++.h>

using namespace std;
#define EPS 1e-9
#define maxn 2000005

int n;
bitset<maxn> dp;

long long sum, ans;

int main(){

    cin >> n;

    dp[0] = true;
    for(int i = 0; i < n; i++){
        int inp;
        cin >> inp;
        dp = dp | (dp << inp);
        sum += inp;
    }
    ans = 20000000090;

    for(int i = 0; i <= sum; i++){
        if(dp[i])
            ans = min(ans, abs(sum-2*i) );
    }

    cout << ans << endl;


    return 0;
}
