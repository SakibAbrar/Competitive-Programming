#include <bits/stdc++.h>
using namespace std;

#define INF 1e12

double AB, AC, BC;
double givenAreaRatio, ans;


double areaRatio(double ab,double ac,double bc,double ad)
{
    double ae,de,s1,s2,largeTriangleArea,smallTriangleArea,trapheziumArea, ratio;
    ae = (ad*ac)/ab;
    de = (ad*bc)/ab;

    s1 = (ab+ac+bc)/2.0;
    s2 = (ad+ae+de)/2.0;
    largeTriangleArea = sqrt(s1 * (s1-ab) * (s1-ac) * (s1-bc));
    smallTriangleArea = sqrt(s2 * (s2-ad) * (s2-ae) * (s2-de));
    trapheziumArea = largeTriangleArea - smallTriangleArea;

    ratio  = smallTriangleArea/trapheziumArea;
    return ratio;
}


double binary_search(double ab, double ac, double bc){

    double low = 0.0, hi = ab, mid;

    for(int i = 1; i <= 100; i++){
        mid = (hi+low)/2;

        if( areaRatio(ab, ac, bc, mid) > givenAreaRatio )
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
        scanf("%lf %lf %lf %lf", &AB, &AC, &BC, &givenAreaRatio);
        printf("Case %d: %0.10lf\n", ++caseno, binary_search(AB, AC, BC));
    }

    return 0;
}
