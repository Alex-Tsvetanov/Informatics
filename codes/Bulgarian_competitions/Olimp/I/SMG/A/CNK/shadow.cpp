#define Pi 3.1415926535897932384626433832795
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
double a,b,S;
int main()
{
    cin>>a>>b;
    if(a==b)
    {
        S=2*a*b-2*a*b*tan(Pi/8);
        printf("%4.3f\n",S);
    }else
    {
        if(a>b){swap(a,b);}
        S=2*a*b-a*a;
        printf("%4.3f\n",S);
    }
    return 0;
}
