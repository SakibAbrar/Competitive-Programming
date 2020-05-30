#include <bits/stdc++.h>
using namespace std;
// for ordered_set
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define FILEIN freopen("input.txt","r",stdin)
#define FILEOUT freopen("output.txt","w",stdout)
#define DEBUG printf("Works\n")
#define ll long long
#define EPS (1e-8)
#define INF 1000000000
#define mod 1000000007LL
#define maxn 1000005

int T, caseNo;
ll n;
ll ans;

bool isPrime(int x) {
    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0)
            return false;
    }
    return true;
}

/// As lcm(i, j) equals n. at least i or j should
/// contain the maximum power of any prime divisor of n

ll pairsFormLCM( ll n ) {
    ll res = 1;
    for ( ll num = 2; num * num  <= n; num++ ) {
        /// pp contains the primepower for anyprime
        if (n % num == 0) {
            /// as we keep dividing the n with a prime
            /// the next time we'll be having another prime not composite
            ll pp = 0;
            while(n % num == 0) {
                pp ++;
                n /= num;
            }
            // little bit of combinatorics
            // i and j can have pp + 1 configurations where the lcm is n
            res *= (2 * pp + 1);
        }
    }

    // n is still a prime
    if(n > 1) {
        res *= 3;
    }
    // we want i <= j and we know these pairs are symmetrical we can divide it by two
    // as i == j can only happen once rest of the cases can happen twice
    // if it was i < j (res - 1) / 2 should be the answer 
    // as it is i <= j we add 1
    return (res - 1) / 2 + 1;
}

void solve() {
    scanf("%lld",&n);
    printf("Case %d: %lld\n", ++caseNo, pairsFormLCM(n));
}

int main() {
    // FILEOUT
    scanf("%d",&T);
    while(T--)
        solve();
    return 0;
}
