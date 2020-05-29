
#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int maxn = 5 * 1e5 + 5;

long long n, k;
long long ans;
long long  numMultiple;
long long modP = 998244353;

long long fac[maxn];

void genFac() {
	fac[0] = 1; 
	for (int i = 1 ; i < maxn; i++)
		fac[i] = fac[i-1] * i % modP;
}

long long power(long long  x, long long y) { 
	int res = 1; 
	x = x % modP;
	while (y > 0) { 
		if (y & 1) 
			res = (res*x) % modP; 

		y = y>>1;
		x = (x*x) % modP; 
	} 
	return res; 
} 

// Returns n^(-1) modP modP 
long long modInverse(long long n) { 
	return power(n, modP-2);
} 


long long nCrModPFermat(long long n, long long r) { 

    if (r==0) 
	    return 1; 

	return (fac[n]* modInverse(fac[r]) % modP * 
			modInverse(fac[n-r]) % modP) % modP; 
} 

int main() {
    scanf("%lld %lld", &n, &k);

    genFac();

    for (long long num = 1; k * num <= n; num++) {
        numMultiple = n / num;
        // cout << numMultiple << " --- " << nCrModPFermat(numMultiple, 2) <<  endl;
        numMultiple --;
        ans += nCrModPFermat(numMultiple, k - 1);
        ans %= modP;
    }

    printf("%lld\n", ans);

    return 0;
}
