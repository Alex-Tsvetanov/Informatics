#include<iostream>
#include<cmath>
#define PI 3.14159265359

using namespace std;

struct point{
    int x;
    int y;
    point(int a, int b){x=a;y=b;}
    point(){x=0;y=0;}
};

point center;
point g[3][2];

double dist(point a, point b){
    double dy = abs(a.y-b.y);
    double dx = abs(a.x-b.x);
    return sqrt(dx*dx + dy*dy);
}

double angle(point p1, point p2){
    double c = dist(p1,p2);
    double a = dist(p1,center);
    double b= dist(p2, center);
    double cosAngle = (a*a + b*b - c*c)/(2*a*b);
    return acos(cosAngle)*180/PI;
}

int main(){

    int a,b;
    cin >> a >> b;
    center.x = a;
    center.y = b;

    cin >> a >> b;
    g[0][0].x=a;
    g[0][0].y=b;
    cin >> a >> b;
    g[0][1].x=a;
    g[0][1].y=b;

    cin >> a >> b;
    g[1][0].x=a;
    g[1][0].y=b;
    cin >> a >> b;
    g[1][1].x=a;
    g[1][1].y=b;

    cin >> a >> b;
    g[2][0].x=a;
    g[2][0].y=b;
    cin >> a >> b;
    g[2][1].x=a;
    g[2][1].y=b;

    double covered = angle(g[0][1],g[0][0]) + angle(g[1][0],g[1][1]) + angle(g[2][0], g[2][1]);
    double res = (covered/360.0);

    int answer = round(res*100.0);

    if(answer >= 100)cout << 100 << endl;
    else cout << answer << endl;

    return 0;
}
