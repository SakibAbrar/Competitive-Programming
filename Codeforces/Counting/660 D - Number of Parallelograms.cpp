#include<bits/stdc++.h>

using namespace std;
#define EPS 1e-9
#define maxn 100007

typedef long long ll;
typedef pair< int, int> point;

int T, cases;
int n;
int x, y;

void solve(){
    scanf("%d", &n);

        vector<point> points;
        map<point, ll> centerOfDiagonals;

        ll ans = 0; 

        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            points.push_back(make_pair(x, y));
        }
        
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                // We are considering diagonal matches.
                // any parallelogram has a property
                // both diagonal bisect each other in one point
                // so we take any two diagonal and check if their mid point is same
                point p1 = points[i], p2 = points[j];
                point centerTimes2 = make_pair(p1.first + p2.first, p1.second + p2.second);

                ans += centerOfDiagonals[centerTimes2];
                centerOfDiagonals[centerTimes2]++;
            }

        }
        printf("%lld\n", ans);
}

int main(){
    
    //freopen("output.txt", "w", stdout);
    solve();

    return 0;
}
