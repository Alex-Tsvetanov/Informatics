#include<iostream>
#include<vector>
#include<iomanip>
#include<climits>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int n,m,p,i,a,b,flag=0,j;
    cin>>n>>m>>p;
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        for(j=a;j<=b;j++)
        {
            if(j%6==0||j%7==0)flag=1;
        }
    }
    if(flag==0)cout<<"OK"<<endl;
    else cout<<"MIXED"<<endl;
    return 0;
}
