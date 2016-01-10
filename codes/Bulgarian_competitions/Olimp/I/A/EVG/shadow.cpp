#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

const double PI = M_PI;
const double HalfPI = M_PI_2;
const double TwoPI = 2*M_PI;

struct point {
    double x, y;
};

struct quad {
    point points[4];
};

point subPoint(point umalaemo, point umalitel) {
    point c;
    c.x = umalaemo.x - umalitel.x;
    c.y = umalaemo.y - umalitel.y;
    return c;
}

double dist(point a, point b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double orientiranoLice(point a, point b, point c) {
    a = subPoint(a, c);
    b = subPoint(b, c);
    return a.x*b.y-a.y*b.x;
}

point rotatePoint(point a, double rad) { // radiani ili degrees vzimat tezi trigonometrichni funkcii?
    point ans;
    double sinRad = sin(rad);
    double cosRad = cos(rad);
    ans.x = a.x*cosRad-a.y*sinRad;
    ans.y = a.x*sinRad+a.y*cosRad;
    return ans;
}

quad rotateQuad(quad a, double rad) {
    quad ans;
    ans.points[0] = rotatePoint(a.points[0], rad);
    ans.points[1] = rotatePoint(a.points[1], rad);
    ans.points[2] = rotatePoint(a.points[2], rad);
    ans.points[3] = rotatePoint(a.points[3], rad);
    return ans;
}

bool checkSegmentIntersection(point a1, point a2, point b1, point b2) {
    //cout << orientiranoLice(a1, b1, b2) << ' ' << orientiranoLice(a2, b1, b2);
    return (orientiranoLice(a1, b1, b2)*orientiranoLice(a2, b1, b2) < 0); // ako e true znachi intersectvat
}

point findSegmentIntersectionPoint(point a1, point a2, point b1, point b2) {
    point ans;
    return ans;
}

int main() {
    //double a = 1.2d;
    cout << fixed << setprecision(3);
    /*
    point a, b;
    a.x = 2;
    a.y = 3;
    b.x = 2+3;
    b.y = 3+4;
    cout << dist(a, b);*/
    //cout << a;
    //cout << PI;
    //point a;
    //a.x = 1;
    //a.y = 1;
    //a = rotate(a, TwoPI); // -0.000??? normalize?!
    //a = rotate(a, HalfPI/2);
    //cout << a.x << ' ' << a.y;
/*
    quad a;
    a.points[0].x = -1;
    a.points[0].y = -1;
    a.points[1].x =  1;
    a.points[1].y = -1;
    a.points[2].x =  1;
    a.points[2].y =  1;
    a.points[3].x = -1;
    a.points[3].y =  1;

    a = rotateQuad(a, HalfPI/2);

    cout << a.points[0].x << ' ' << a.points[0].y << endl;
    cout << a.points[1].x << ' ' << a.points[1].y << endl;
    cout << a.points[2].x << ' ' << a.points[2].y << endl;
    cout << a.points[3].x << ' ' << a.points[3].y << endl;
    */
/*
    point a1, a2, b1, b2;
    a1.x = -1;
    a1.y =  0;
    a2.x =  1;
    a2.y =  0;
    b1.x = -1;
    b1.y = -1;
    b2.x =  1;
    b2.y =  1;
    cout << checkSegmentIntersection(a1, a2, b1, b2);
*/
    // priemame, che a = b;
    double a, b;
    cin >> a >> b;
    cout << (a*a+2*a*(sqrt(2)-1));
    cout << endl;
    return 0;
}
