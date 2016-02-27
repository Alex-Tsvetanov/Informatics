#define PI 3.14159265359
#include<iostream>
#include<cmath>
using namespace std;
struct point{
    int x,y;
};
bool surface(point a,point b)
{
    return ((a.x-b.x)*(a.y-b.y)+ a.x*a.y + b.x*b.y)>0;
}
int main()
{
    int a,b,first=1,second=3,third=5;
    cin>>a>>b;
    point center,guards[6];
    center.x=a;
    center.y=b;
    for(int i=0;i<6;++i)
    {
        cin>>guards[i].x>>guards[i].y;
        guards[i].x-=center.x;
        guards[i].y-=center.y;
    }
    center.x=center.y=0;
    if(!surface(guards[1],guards[2]))
    {
        first=2;
    }
    if(!surface(guards[3],guards[4]))
    {
        second=4;
    }
    if(!surface(guards[5],guards[0]))
    {
        third=0;
    }
    double angle1 = atan2(sqrt(guards[0].x*guards[0].x+guards[0].y*guards[0].y),sqrt(guards[first].x*guards[first].x+guards[first].y*guards[first].y));
    double angle2 = atan2(sqrt(guards[2].x*guards[2].x+guards[2].y*guards[2].y),sqrt(guards[second].x*guards[second].x+guards[second].y*guards[second].y));
    double angle3 = atan2(sqrt(guards[4].x*guards[4].x+guards[4].y*guards[4].y),sqrt(guards[third].x*guards[third].x+guards[third].y*guards[third].y));
    int ans = (((angle1+angle2+angle3)/(2*PI))*100 + 0.5);
    cout<<ans<<endl;
    return 0;
}
