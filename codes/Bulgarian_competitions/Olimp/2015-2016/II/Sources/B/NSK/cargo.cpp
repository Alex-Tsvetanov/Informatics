#include<iostream>
using namespace std;
long long days, br, pilots, i, j, x, y, a[100001], ok, ans;
int main()
{
    cin>>days>>br>>pilots;
    for(i=1; i<=br; i++)
    {
        cin>>x>>y;
        ok=0;
        for(j=x; j<=y; j++)
        {
            if(a[j]==0) a[j]=1;
            else ok++;
        }
        if(ok==y-x+1) ans=-1;
    }
    if(ans==-1) {cout<<"IMPOSSIBLE"<<endl; return 0;}
    for(i=1; i<=days; i++)
    {
        if((i%7==6 || i%7==0) && a[i]==1) ans=-1;
    }
    if(ans==-1) cout<<"MIXED"<<endl;
    else
    cout<<"OK"<<endl;
    return 0;
}
