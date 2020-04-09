#include <bits/stdc++.h>

using namespace std;


int arr[2005];
int N;
int sum;
int range; 
long long ans;

int main(){



    //freopen( "output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int caseno = 0, cases;
    scanf("%d", &cases);
    while(cases-- ) {
        scanf(" %d", &N);
        ans = 0;

        for (int idx = 0; idx<N; idx++){
            scanf(" %d", &arr[idx]);
        }

        sort(arr, arr+N);

        for(int idx1 = 0; idx1<N; idx1++){
            for(int idx2 = idx1+1; idx2<N; idx2++){
                
                sum = arr[idx1] + arr[idx2];

                range = upper_bound(arr, arr+N, sum - 1) - arr; 

                range -= idx2;
                range --;

                ans += range;
            }
        }

        printf("Case %d: %lld\n", ++caseno, ans);
    }

    
    return 0;
}
