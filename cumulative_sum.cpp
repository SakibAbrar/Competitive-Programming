#include<bits/stdc++.h>

using namespace std;

int arr[11], sum[11];

int main(){

    for(int i = 1; i<=7; i++){
        cin >> arr[i];
    }

    for(int i = 1; i<=7; i++){
        sum[i] = sum[i-1] + arr[i];

        cout << sum[i] << " ";
    }

    cout << endl;

    cout << sum[5] - sum[0] << endl;


    return 0;
}
