#include <bits/stdc++.h>

using namespace std;

int weight[25];
bool possible[2000005];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;
    possible[0] = true;

    for(int idx = 0; idx<n; idx++){
        cin >> weight[idx];
        sum += weight[idx];
    }

    int ans = sum;

    possible[0] = true;
    
    // this dp should ensure that the rocks are used only once
    for(int idx = 0; idx<n; idx++){
        for(int wt = sum;  wt>=1; wt--){

            if(possible[wt-weight[idx]] && wt>=weight[idx]){
                possible[wt] = true;
                ans = min(ans, abs(sum-2*wt));

            }
        }

    }

    cout << ans << endl;

}
