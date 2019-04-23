#include <bits/stdc++.h>

using namespace std;

int weight[25];

//mask will be the state of this dp array sum
//we'll count all the ones of any mask state and add weights of those indices
//adding those manually by a O(n) loop for every state, make it a total of O(n.2^n)
//we can reduce it to O(2^n)

int sum[1<<20];

int total;
int ans;

int main(){

    int n;
    cin >> n;

    for( int idx = 0; idx<n; idx++){
        cin >> weight[idx];
        total+=weight[idx];
    }
  
    //taking a large value initially for the answer
    ans = total;

    sum[0] = 0;

    for(int i = 0; i<n; i++){
        for(int mask = 1<<i; mask < (1<<(i+1)); mask++){
            // mask er age jokhon mask er ith bit off chilo tokhon er weight + ith weight = current
            // 2^(i) theke 2^(i+1) porjonto ith bit must on thake
            sum[mask] = sum[mask^(1<<i) ] + weight[i];
            ///taking the difference of total-sum[mask] and sum[mask]
            ans = min(ans, abs(total-2*sum[mask]));
        }
    }
    cout << ans << endl;
}
