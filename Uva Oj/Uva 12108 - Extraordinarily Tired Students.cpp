#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int> > piii;
// pair<c, <a, b>> stored in this format
// cycle length can be get using piii.second.frist + piii.second.second or a+b


piii arr[12];

int  main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cases = 0;
    int cyc;

    freopen("output.txt", "w", stdout);

    while(cin>>n, n){
        cyc = 1;

        for( int idx = 0; idx<n; idx++){
            int a, b, c;
            cin >> a >> b >> c;
            arr[idx].first = c;
            arr[idx].second.first = a;
            arr[idx].second.second = b;
            cyc *= (a+b);
        }

        int awake, sleep;
        int ret = -1;

        for(int time = 1; time<= cyc; time++){
            awake = 0, sleep = 0;

            for(int std = 0; std<n; std++){
                if(arr[std].first <= arr[std].second.first )
                    awake++;
                else 
                    sleep++;
            }

            if(awake==n){
                ret = time;
                break;
            }

    
            for(int std = 0; std<n; std++){
                arr[std].first+=1;

                if(arr[std].first == arr[std].second.first + 1  &&  awake >= sleep){
                    arr[std].first = 1;
                }

                else if(arr[std].first == arr[std].second.first + arr[std].second.second + 1)
                    arr[std].first = 1;
            }

        }

        printf("Case %d: %d\n", ++cases, ret);

    }
}
