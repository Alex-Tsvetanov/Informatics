#include<cstdio>
#include<cmath>
#define eps 0.000001
using namespace std;
int main()
{
    double a,b,s,s1,ms,i,r,t,l;
    scanf("%lf%lf",&a,&b);ms=1;l=((a*a)/(b*b)+1)/4;
    if(a==b){s=a*a*(4-2*sqrt(2.0));}
    else
    {
        if(a<b){s=a;a=b;b=s;}
        s=b*(2*a-b);t=a/b+b/a;
        for(i=0.25;i<l;i+=eps)
        {
            s1=i*(2-sqrt(4*i-1)*t)/(1-2*i);
            if(s1<ms){ms=s1;}
        }
        s1=(2-ms)*a*b;if(s1>s){s=s1;}
    }
    printf("%.3lf\n",s);
    return 0;
}
