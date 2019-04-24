#include <bits/stdc++.h>

using namespace std;

int sum[10005];
int times[40];

int ans;

int main(){

    int n;
    cin >> n;
    //we'll consider
    n/=2;

    int upto = pow(10, n) - 1;
    
    //this count the sum of the digits of any number through a dp approach in O(n)
    for(int num = 0; num<=upto; num++){
        sum[num] = sum[num/10] + num%10;
    }

    //this keeps the count or frequency of any sum of digit of numbers
    for(int num = 0; num<=upto; num++){
        times[sum[num]]++;
    }

    //this counts the summation of all possibilities for a n digit number having a particular sum 
    //on the both halves of the number. If there are k ways for the half to have a particular sum
    //another k ways for the other half making it k*k ways to form the whole number.

    for(int idx = 0; idx<=9*n; idx++){
        ans+=times[idx]*times[idx];
    }

    cout << ans << endl;

}
