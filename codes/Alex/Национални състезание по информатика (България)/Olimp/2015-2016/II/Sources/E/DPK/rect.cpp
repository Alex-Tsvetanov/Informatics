#include <iostream>
using namespace std;
int main ()
{
    int n,a,b,c,d,e,i,br=0;
    cin>>n;
    for (a=1;a<=n;a++)
    {
       for (b=a;b<=n/2;b++)
       {
           e=a+1;
           d=b-1;
           c=(e*d)+(a*b);
           if (c==n){br++;}
       }
    }
    cout<<br<<endl;
    return 0;
}
