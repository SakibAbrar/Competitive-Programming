#include <bits/stdc++.h>
using namespace std;

double x, y, c, b, ansH, low, hi, mid;


double binary_search(){
    low = 0.0;
    hi = min(x, y);

    for(int i = 0; i<64; i++){

        mid = (low + hi)/2.0;
        b = mid; 
        
        ansH = ( sqrt(x*x-b*b) * sqrt(y*y-b*b) )/( sqrt(x*x-b*b) + sqrt(y*y-b*b) );
        // hx * hy/(hx + hy)

        if( ansH < c)
            hi = mid;
        else 
            low = mid;
    }

    return mid;

}

int main()
{   
    //freopen( "output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while(cases-- ) {
        scanf("%lf %lf %lf", &x, &y, &c);
        printf("Case %d: %0.10lf\n", ++caseno, binary_search());
    }

    return 0;
}
