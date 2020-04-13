#include <bits/stdc++.h>
#define PI (acos(-1.0))
#define INF INT_MAX/2
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define mp make_pair
using namespace std;
 
///cout << fixed << setprecision(12) << p << endl;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

const int mx = 1e5+5;
const int MOD = 1e9+7;
 
int n;
int T;

void solve(){
    scanf("%d", &n);
    ll maxNum = -1e9 - 7;
    ll ans = -1e9 - 7;
    ll  inp;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &inp);
        maxNum = max(maxNum, inp);
        ans = max(ans, maxNum - inp);
    }

    ll x = ans;

    if(x == 0)
        ans = 0;
    else if(__builtin_popcountll(x) == 1){
        ans = log2(x & -x) + 1;
    }
    else {
        ans = 64 - __builtin_clzll(x);
    }
    printf("%lld\n",ans);
    

}
 
int main(){
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    scanf("%d", &T);
 
    while(T--){
        solve();
    }
 
    return 0;
}
