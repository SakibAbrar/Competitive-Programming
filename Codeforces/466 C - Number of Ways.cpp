#include <stdio.h>

#define INF 1e9

long long sum, oneThird, testSum;
long long ans;

const int N = 5 * 1e5 + 5;
int n;
int arr[N];
int pref[N];

int main() {

    scanf("%d", &n);

    for (int idx = 0; idx < n; idx ++) {
        scanf("%d", arr + idx);
        sum += arr[idx];
    }
    

    if (sum % 3 != 0) {
        printf("0\n");
    }
    else {
        oneThird = sum / 3;
        testSum = 0;
        for (int idx = n - 1; idx >= 2; idx --) {
            testSum += arr[idx];
            pref[idx] = pref[idx + 1];
            if (testSum == oneThird)
                pref[idx] += 1;
        }

        testSum = 0;
        for (int idx = 0; idx < n - 2; idx ++) {
            testSum += arr[idx];
            if(testSum == oneThird)
                ans += pref[idx + 2];
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
