#include <cmath>
#include<iostream>
#define M_PI	3.14159265358979323846


using namespace std;

int main ()
{
    int centerX, centerY;
    double ans = 0;
    cin >> centerX >> centerY;
    int x[3][2], y[3][2];
    for(int i = 0; i < 3; ++i)
        cin >> x[i][0] >> y[i][0] >> x[i][1] >> y[i][1];
    int i = 0, j, k;
    bool used[3];
    used[0] = false;
    used[1] = false;
    used[2] = false;
        double c = sqrt(((x[0][0]-x[0][1])*(x[0][0]-x[0][1]))+((y[0][0]-y[0][1])*(y[0][0]-y[0][1])));
        double a = sqrt(((x[0][0]-centerX)*(x[0][0]-centerX))+((y[0][0]-centerY)*(y[0][0]-centerY)));
        double b = sqrt(((x[0][1]-centerX)*(x[0][1]-centerX))+((y[0][1]-centerY)*(y[0][1]-centerY)));
        double minn = acos((a*a + b*b - c*c)/(2*a*b))*180/M_PI;
        ans += minn;
        c = sqrt(((x[1][0]-x[1][1])*(x[1][0]-x[1][1]))+((y[1][0]-y[1][1])*(y[1][0]-y[1][1])));
        a = sqrt(((x[1][0]-centerX)*(x[1][0]-centerX))+((y[1][0]-centerY)*(y[1][0]-centerY)));
        b = sqrt(((x[1][1]-centerX)*(x[1][1]-centerX))+((y[1][1]-centerY)*(y[1][1]-centerY)));
        minn = acos((a*a + b*b - c*c)/(2*a*b))*180/M_PI;
        ans += minn;

        c = sqrt(((x[0][0]-x[1][1])*(x[0][0]-x[1][1]))+((y[0][0]-y[1][1])*(y[0][0]-y[1][1])));
        a = sqrt(((x[0][0]-centerX)*(x[0][0]-centerX))+((y[0][0]-centerY)*(y[0][0]-centerY)));
        b = sqrt(((x[1][1]-centerX)*(x[1][1]-centerX))+((y[1][1]-centerY)*(y[1][1]-centerY)));
        minn = acos((a*a + b*b - c*c)/(2*a*b))*180/M_PI;

        if(minn < ans)
            ans = minn;

        c = sqrt(((x[2][0]-x[2][1])*(x[2][0]-x[2][1]))+((y[2][0]-y[2][1])*(y[2][0]-y[2][1])));
        a = sqrt(((x[2][0]-centerX)*(x[2][0]-centerX))+((y[2][0]-centerY)*(y[2][0]-centerY)));
        b = sqrt(((x[2][1]-centerX)*(x[2][1]-centerX))+((y[2][1]-centerY)*(y[2][1]-centerY)));
        minn = acos((a*a + b*b - c*c)/(2*a*b))*180/M_PI;
        ans += minn;
    int q = ans/360*100;
    if (q > 100)
        q = 100;
    cout << q << endl;
    return 0;
}
/*
0 0
100 -1 0 100
0 120 -50 -95
-60 -90 90 10
*/
