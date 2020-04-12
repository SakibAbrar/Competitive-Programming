#include<bits/stdc++.h>

using namespace std;
#define EPS 1e-9
#define maxn 100007
#define INF 1e200
typedef long long ll;


struct point_i{
    int x, y;
    point_i() {x = y = 0;}
    point_i(int _x, int _y): x(_x), y(_y) {}

    bool operator < (point_i another) const{
        if(x != another.x)
            return x < another.x;
        else
            return y < another.y;
    }

    bool operator == (point_i another) const{
        return x == another.x && y == another.y;
    }

};

struct point{
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y): x(_x), y(_y) {}

    bool operator < (point another) const{
        if(fabs(x - another.x) > EPS)
            return x < another.x;
        else
            return y < another.y;
    }

    bool operator == (point another) const{
        return fabs(x - another.x) < EPS && fabs(y - another.y) < EPS;
    }

};

struct line{
    double a, b, c;
    line(){a = b = c = 0;}
    /// ax + by + c = 0 given a, b, c
    line(double _a, double _b, double _c): a(_a), b(_b), c(_c) {}
    /// y = mx + c form given m and a point within
    line (double m, point passingPoint) : 
        line(fabs(m - INF) < EPS ? 1.0 : -m,
             fabs(m - INF) < EPS ? 0.0 : 1.0, 
             fabs(m - INF) < EPS ? -passingPoint.x : m * passingPoint.x - passingPoint.y){
        //this way it doesn't work had to use delegation of constructor
        //if vertical line pass INF here as slope m
        // if(fabs(m - INF) < EPS){
        //     line(1.0, 0.0, passingPoint.x);
        //     cout << "vertical line nigga" << endl;
        // }
        // else{
        //     cout << "not a vertical line nigga" << endl;
        //     line(-m, 1.0, -m * passingPoint.x + passingPoint.y);
        // }
    }

    // given two passing point form a equation
    line (point firstPoint, point secondPoint):
        line(fabs(firstPoint.x - secondPoint.x) < EPS ? INF : (firstPoint.y - secondPoint.y) / (firstPoint.x - secondPoint.x),
        firstPoint ){
        //this way it doesn't work had to use delegation of constructor
        //if it is a vertical line
        // if(fabs(firstPoint.x - secondPoint.x) < EPS)
        //     line(INF, firstPoint);
        // else 
        //     line((firstPoint.y - secondPoint.y) / (firstPoint.x - secondPoint.x), firstPoint);
    }

    // if two line is equal
    bool operator == (line another) const{
        double ratioA, ratioB, ratioC;
        ratioA = a / another.a;
        ratioB = b / another.b;
        ratioC = c / another.c;
        return fabs(ratioA - ratioB) < EPS && fabs(ratioB - ratioC) < EPS;
    }

    line getPerpendicularLine(point passingPoint){
        
        if(fabs(a) < EPS)
            return line(INF, passingPoint);
        else if(fabs(b) < EPS)
            return line(0, passingPoint);
        else
            return line(b / a, passingPoint);
    }

    // if two line is parallel
    // use line1 || line2 to check if these are parallels
    bool operator || (line another) const{
        double ratioA, ratioB, ratioC;
        ratioA = a / another.a;
        ratioB = b / another.b;
        return fabs(ratioA - ratioB) < EPS;
    }

    // if two line intersects. 
    // pass a point as sectP to store the intersection point
    bool intersectWith(line another, point& sectP){
        if( *(this) || another)
            return false;
        line l1 = *(this), l2 = another;

        sectP.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
        // test for vertical line to avoid division by zero
        if(fabs( l1.b ) > EPS)
            sectP.y = -(l1.a * sectP.x + l1.c);
        else
            sectP.y = -(l2.a * sectP.x + l2.c);

        return true;
    }
};


int main(){
    
    
    return 0;
}
