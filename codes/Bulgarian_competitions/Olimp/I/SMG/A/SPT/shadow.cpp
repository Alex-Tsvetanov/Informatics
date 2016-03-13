#include<iostream>
#include<cmath>
using namespace std;
double a,b,c,ans1,ans2,ans3,ans;
int main()
{
    cin>>a>>b;
    if(a==b)
    {
        ans=a*a*(2.5-sqrt(2));
    }
    else
    {
        if(b>a)
        {
            c=a;
            a=b;
            b=c;
        }
        if(a<(b*(1+sqrt(2))))
        {
            ans3=a*b*(2-sqrt(2))+(a*a+b*b)*(1-sqrt(2)/2);
        }
        ans1=2.0*a*b-b*b;
        ans2=a*b*3.0/2.0-b*b*b/a/2.0;
        if(ans1>ans2&&ans1>ans3)
        {
            ans=ans1;
        }
        else if(ans2>ans3)
        {
            ans=ans2;
        }
        else
        {
            ans=ans3;
        }
    }
    ans=ans*1000;
    ans=round(ans);
    ans=ans/1000;
    cout<<ans;
    return 0;
}
