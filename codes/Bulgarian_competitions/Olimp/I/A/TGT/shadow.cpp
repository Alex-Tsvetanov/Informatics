#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    double a,b;
    cin>>a>>b;
    double smallDiagonal = a*(sqrt(2)-1);
    if(a==b)
    {
        printf("%.3f\n",a*a+smallDiagonal*smallDiagonal*2);
        return 0;
    }
    printf("%.3f\n",a*b*118.44242/100);
    return 0;
}

