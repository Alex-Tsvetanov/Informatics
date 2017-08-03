// Task poly
// Author Plamenka Hristova
#include <iostream>
#include <stdlib.h>
using namespace std;
int n, y1[1000], y2[1000], x[1000];
long s=0;
int cross(double a, long b, long c)
{
    return b<a && a<c;
}
int inside(int k)
{
    double a=y1[k]+0.5, d=x[k]+0.5;
    int c=0;
    for(int i=0;i<n;i++){
        if(x[i]>d)
          if(cross (a, y1[i], y2[i]))c++;
    }
   return c%2;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y1[i]>>y2[i];
    }
    for(int i=0;i<n;i++){
        long st=x[i]*(y2[i]-y1[i]);
        if(inside(i))s-=st;
        else s+=st;
    }
    cout<<abs(s)<<endl;
    return 0;
}
