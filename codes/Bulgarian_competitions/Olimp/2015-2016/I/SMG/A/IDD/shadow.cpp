#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
const double Pi=3.1415926535897932384626433832795;
double a,b,d,beta,beta2,malpha;
double ans,cans;
int main(){
    cin>>a>>b;
    if (a<b){swap(a,b);}
    d=sqrt(a*a+b*b);
    beta=asin(a/d);
    beta2=asin(b/d);
    d/=2.0;
    for (double alpha=0; alpha+2*beta<Pi; alpha+=0.00001){
        double x,y,xs,ys;
        x=d*sin(beta)/sin(alpha+beta);
        y=d*sin(beta2)/sin(alpha+beta2);
        xs=d*sin(alpha)/sin(alpha+beta);
        ys=d*sin(alpha)/sin(alpha+beta2);
        cans=((d-x)*(d-x)/xs/xs + (d-y)*(d-y)/ys/ys)*d*d*tan(alpha);
        if (ans<cans){ans=cans;}
    }
    //cout<<2*beta - Pi/2<<endl;
    for (double alpha=0; alpha<2*beta-Pi/2; alpha+=0.00001){
        double x,y;
        x=d*sin(alpha/2)/sin(alpha/2+beta2);
        cans=(2*x+b*tan(-alpha+Pi/2-2*beta2))*b;
        if (ans<cans){ans=cans;}
    }
    printf("%.3lf",a*b+ans);
    return 0;
}
