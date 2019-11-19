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

long long dp[30][160];
long long power[30];
int n, x;

void gen(){
    power[0] = 1;
    for(int i = 1; i<30; i ++){
        power[i] = power[i-1]*6;
    }
}

long long solve(int diceN, int sum){

    if(diceN > n){
        if(sum >= x)
            return 1;
        else
            return 0;
    }

    if(dp[diceN][sum] != -1)
        return dp[diceN][sum];

    dp[diceN][sum] = 0;

    for(int i = 1; i <= 6; i++) 
        dp[diceN][sum] += solve(diceN+1, sum+i);
    
    return dp[diceN][sum];
}



int main(){

    int T;
    cin >> T;


    for( int cases = 1; cases <= T; cases++){

        memset(dp, -1, sizeof(dp));

        cin >> n >> x;
        ll u = solve(1, 0);
        gen();
        ll v = power[n];
        ll g = gcd(u, v);
        u/=g;
        v/=g;

        cout << "Case " << cases << ": " << u ;
        if(v != 1 && u != 0) 
            cout << '/' << v ;
        cout << endl;
    }
    
    return 0;
}
