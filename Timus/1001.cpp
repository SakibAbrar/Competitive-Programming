#include <bits/stdc++.h>

using namespace std;

int main(){

    long long num;

    vector <string> vecString;

    while(cin >> num){

        
        vecString.push_back(to_string(num));

    }

    for(int idx = vecString.size()-1; idx>=0; idx--){

        printf("%.6lf\n", sqrt(stoll(vecString[idx])));

    }

}
