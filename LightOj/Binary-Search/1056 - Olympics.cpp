#include<bits/stdc++.h>

using namespace std;
#define EPS 1e-9

double a, b, length, radius,  width;
double theta, thetaExpected, perim, arc, arcExpected;

double hi, lo, mid;

int T, cases;
char baad;

int main(){
    //freopen("output.txt", "w", stdout);
    cin >> T;

    while(++cases <= T){
        cin >> a >> baad >> b;

        hi = 200;
        lo = 0;
            
        while(fabs(lo-hi) > EPS){

            length = mid = (lo + hi)/2.0;
            width = (length * b)/a;
            arcExpected = 0.5 * (400.0 - 2 * length);
            
            radius = 0.5 * sqrt(length * length + width * width);
            theta = acos( (2 * radius * radius - width * width)/ (2 * radius * radius) );
            //calculated arc
            arc = radius * theta;
            
            if( arcExpected > arc )
                lo = mid;
            else 
                hi = mid;
        }
        cout << "Case " << cases << ": ";
        cout << setprecision(12)  << length << " " << width << endl;
    }
    

    return 0;
}
