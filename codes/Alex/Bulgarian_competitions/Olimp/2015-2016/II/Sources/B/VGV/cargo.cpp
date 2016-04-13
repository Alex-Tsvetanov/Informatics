#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,p;
vector<int>v[1000000];
int otg=1,da=0;
void Read()
{
    int i,x,y;
cin>>n>>m>>p;
    p/=2;
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
       v[i].push_back(x);
       v[i].push_back(y);
       v[i].push_back(1);
    }
}
void Resh()
{
    int i;
    sort(v,v+m);
    for(i=1;i<m;i++)
    {
        if(v[i][1]<=v[i+1][1]&&v[i][0]<=v[i+1][0])
        {
            if(v[i][0]<=v[i+1][0]) v[i+1][0]=v[i][0];
            if(v[i][1]>v[i+1][1])  v[i+1][1]=v[i][1];
            v[i+1][2]=v[i][2]+v[i+1][2];
            v[i][2]=0;
        }
        if(v[i+1][2]>v[i+1][1]-v[i+1][0])
        {
            otg=-1;
        }
        if(v[i+1][2]=v[i+1][1]-v[i+1][0]&&6-v[i+1][0]%6-v[i+1][2]<0)
        {
            otg=0;
        }
    }
    for(i=1;i<=m;i++)
    {
        da+=v[i][2];
    }
}
int main()
{
    int i;
    Read();
    Resh();
    cout<<da<<endl;
    if(da>n) otg=-1;
    if(otg==1) cout<<"OK";
    if(otg==0) cout<<"MIXED";
    if(otg==-1) cout<<"IMPOSSIBLE";
return 0;
}
