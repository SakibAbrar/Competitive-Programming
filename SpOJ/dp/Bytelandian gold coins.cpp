#include <iostream>
#include <map>

using namespace std;

map<int, long long> dp;

int n;

long long f(int n){

    if(n == 0) return 0;

    if(dp[n]!=0) return dp[n];

    dp[n] = n;

    return dp[n] = max(dp[n], f(n/2)+f(n/3)+f(n/4) );

}

int main(){

    while(cin >> n){
        cout << f(n) << endl;
    }
}
