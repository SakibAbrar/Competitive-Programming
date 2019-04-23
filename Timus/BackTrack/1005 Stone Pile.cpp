#include <bits/stdc++.h>

using namespace std;

int ans, total, n;
int weight[25];

void backtrack(int idx, int part1sum){

    //after reaching end 
    if(idx==n){
        int part2sum = total-part1sum;
        ans = min(ans, abs(part2sum-part1sum));
        return;
    }
    //taking idx 
    backtrack(idx+1, part1sum + weight[idx]);
    //not taking idx
    backtrack(idx+1, part1sum);

}

int main(){

    cin >> n;

    for(int idx = 0; idx<n; idx++){
        cin >> weight[idx];
        total+=weight[idx];
    }

    ans = total;

    backtrack(0, 0);

    cout << ans << endl;

}
