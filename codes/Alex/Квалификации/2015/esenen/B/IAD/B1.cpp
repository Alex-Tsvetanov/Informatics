#include <iostream>
#include <cmath>
using namespace std;
struct point
{
    int x;
    int y;
};
int main()
{
    int n = 1;
    int ans = 0;
    int curr = 1;
    int minv = 999999999;
    double mins = 999999999;
    while(n != 0)
    {
        point figura[100];
        cin >> n;
        if(n == 0) break;
        int minx = 999999999, miny = 999999999, maxx = -999999999, maxy = -999999999;
        for(int i = 0; i < n; i ++)
        {
            int a, b;
            cin >> a >> b;
            figura[i].x = a;
            figura[i].y = b;
            minx = min(minx, a);
            miny = min(miny, b);
            maxx = max(maxx, a);
            maxy = max(maxy, b);
        }
        double s = (maxx-minx)*(maxy-miny);
        point a[4];
        a[0].x = minx;
        a[0].y = miny;
        a[1].x = maxx;
        a[1].y = miny;
        a[2].x = minx;
        a[2].y = maxy;
        a[3].x = maxx;
        a[3].y = maxy;
        for(int i = 0; i < 4; i ++)
        {
            point p1, p2;
            p1 = a[i];
            p2 = a[i];
            bool f = false;
            for(int j = 0; j < n; j ++)
            {
                if(figura[j].x == a[i].x && !f)
                {
                    p1 = figura[j];
                    f = true;
                }
                else if(figura[j].y == a[i].y && f)
                {
                    p2 = figura[j];
                    s -= abs(p1.y-a[i].y)*abs(p2.x-a[i].x)*1./2.;
                    p1.x = a[i].x;
                    p1.y = a[i].y;
                    p2.x = a[i].x;
                    p2.y = a[i].y;
                    f = false;
                }
            }
        }
        if(s < mins)
        {
            mins = s;
            ans = curr;
            minv = n;
        }
        if(s == mins)
        {
            if(minv > n)
            {
                ans = curr;
                minv = n;
            }
        }
        curr ++;
    }
    cout << ans << endl;
}

