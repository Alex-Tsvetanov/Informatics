#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int d,n,a,b,br=0;
    cin>>n;
    b=sqrt(n);
    for(a=1;a<b;a++)
    {
        d=a*2+1;
        for(int m=a*3+1;m<=n;m=m+d)
        {
            if(m==n){br++;}
        }

    }
    cout<<br<<endl;
    return 0;
}
