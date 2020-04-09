#include<bits/stdc++.h>

using namespace std;
#define EPS 1e-9
#define maxn 100007

int T, cases;
int n, q;
int arr[maxn];

int main(){
    
    //freopen("output.txt", "w", stdout);
    scanf("%d", &T);

    while(++cases <= T){
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; i++){
            scanf("%d", arr + i);
        }

        sort(arr, arr + n);
        
        printf("Case %d:\n", cases);
        for(int i = 0; i < q; i++){
            int a, b;
            scanf("%d %d", &a, &b);

            printf("%d\n", int(upper_bound(arr, arr + n, b) - lower_bound(arr, arr + n, a)) );
        }
    }
    

    return 0;
}
