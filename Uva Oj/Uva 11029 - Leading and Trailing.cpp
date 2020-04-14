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
 


long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int T;
int n, k;

void solve(){
    scanf("%d %d", &n, &k);
    ll trail = binpow( n, k, 1000 );
    
    /// using logarithm to get those trailing digits.
    /// first taking the exponent from the number as log10(n^k)
    /// then getting only the values after the decimal point
    /// answer is (10^exp)*100.0 we already got 1 digit while raising power so multiply 100 to get two more. not 1000.
    double exponent = k * log10(n);
    exponent -= floor(exponent);

    ll lead = pow(10, exponent) * 100.0;

    printf("%03lld...%03lld\n", lead, trail);
}
 
int main(){
    //freopen("output.txt", "w", stdout);
 
    scanf("%d", &T);
    while(T--){
        solve();
    }
    return 0;
}
