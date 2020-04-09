#include <bits/stdc++.h>
#define PI (acos(-1.0))
#define INF INT_MAX/2
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define mp make_pair
#define endl '\n'
using namespace std;
 
///cout << fixed << setprecision(12) << p << endl;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
 
template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b, a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
 
const int mx = 1e5+5;
const int MOD = 1e9+7;

#define maxN 109

long long power[30];
int n, x;

void gen(){
    power[0] = 1;
    for(int i = 1; i<30; i ++){
        power[i] = power[i-1]*6;
    }
}

void solve(){
    cin >> n >> x;
    vector< vector<ll> > dp(n + 1, vector<ll> (x + 1, 0) );

    dp[0][x] = 1;//base case doesn't mean it can't be an upper one

    for(int i = 1; i<=n; i++){
        for(int j = 0; j <= x; j++ ){
            for(int k = 1; k <= 6; k++){
                dp[i][j] += dp[i-1][min(j+k, x)]; 
                // as the sum should be at least x
            }
        }
    }
    ll u = dp[n][0];
    ll v = power[n];
    ll g = gcd(u, v);
    u/=g;
    v/=g;
    
    cout << u ;
    if(v != 1 && u != 0) 
        cout << '/' << v ;
    cout << endl;

}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int T;
    cin >> T;
    gen();
    
    for( int cases = 1; cases <= T; cases++){

        cout << "Case " << cases << ": ";
        solve();
        
    }
    
    return 0;
}
