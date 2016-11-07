#include  <iostream>
#include  <cstdlib>
#include  <algorithm>
#include  <cmath>
#include  <string>
#include  <windows.h>
using  namespace  std;
int main()
{
    int N;
    cin>>N;
    int M;
    cin>>M;
    int P;
    cin>>P;
    int a1,b1;
    bool dali=false;
    for(int i=0;i<M;i++)
    {
        cin>>a1>>b1;
        if(a1>=6&&a1%6==0||b1>=7&&b1%7==0)
        {
            dali=true;
        }
    }
    if(dali==true) cout<<"MIXED";
    else cout<<"IMPOSSIBLE";






return 0;

}
