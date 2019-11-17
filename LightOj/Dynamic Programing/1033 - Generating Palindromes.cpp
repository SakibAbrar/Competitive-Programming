#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX/2
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
using namespace std;
 
///cout << fixed << setprecision(12) << p << endl;
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;
 
template <class T> inline T bigmod(T p,T e,T M){
    ll ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
 
const int mx=1e5+5;
const int MOD=1e9+7;

#define maxN 109

string inpStr;
int dp[maxN][maxN];

int minIns(int start, int finish){
    
    if(dp[start][finish] != -1)
        return dp[start][finish];
    
    if(start == finish)
        return dp[start][finish] = 0;
    
    if(start+1 == finish)
        return dp[start][finish] = (inpStr[start] != inpStr[finish]);

    if(inpStr[start] == inpStr[finish])
        return dp[start][finish] = minIns(start+1, finish-1);
    
    return dp[start][finish] = 1 + min( minIns(start+1, finish), minIns(start, finish-1));
}

int solve(){
    memset(dp, -1, sizeof(dp));
    return minIns(0, inpStr.size()-1);
}


int main(){
    int T;
    cin >> T;

    for( int cases = 1; cases<=T; cases++){
        cin >> inpStr;
        cout << "Case " << cases << ": " << solve() << endl;
    }
    
    return 0;
}
