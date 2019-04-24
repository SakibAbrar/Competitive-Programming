#include <bits/stdc++.h>

using namespace std;

#define maxn 105
#define PI acos(-1)

typedef pair<float, float> pff;

double dis(pff p1, pff p2){
    return sqrt((p1.first-p2.first)*(p1.first-p2.first) + (p1.second-p2.second)*(p1.second-p2.second));
}

double ans;

int main(){

    int n;
    cin >> n;
    double r;
    cin >> r;
    
    pff pf, pc1, pc2;
    cin >> pf.first >> pf.second;
    pc1 = pf;
    pc2 = pf;

    for(int idx = 1; idx < n; idx++){
        cin >> pc2.first >> pc2.second;
        ans+=dis(pc1, pc2);
        pc1 = pc2;
    }

    ans+= dis(pf, pc2);

    ans+=2*PI*r;

    printf("%.2lf\n",ans);

}
