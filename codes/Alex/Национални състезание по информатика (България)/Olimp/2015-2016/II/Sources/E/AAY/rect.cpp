#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,br=0,a,b;
    cin>>n;
    for(a=1;a<=n-1;a++)
    {
     for(b=1;b<=n-1;b++)
     {
         if(b*a+b+a*b+a==n)br++;
     }

    }
    cout<<br/2<<endl;


}
