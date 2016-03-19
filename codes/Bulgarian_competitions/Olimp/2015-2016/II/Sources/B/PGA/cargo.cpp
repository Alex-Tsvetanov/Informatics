#include <iostream>
#include <cstdio>
using namespace std;
struct day
{
    int s,f;
};
int brs[1000000];
int brs2[1000000];
day d[10000000];
int main()
{
    int n,m,p,i,k,br=0;
    cin>>n>>m>>p;
    p/=2;
    for(i=0;i<m;i++)
    {
        cin>>d[i].s>>d[i].f;
    }
    for(i=0;i<m;i++)
    {
        for(k=d[i].s;k<=d[i].f;k++)
        {
            if(k%6!=0&&k%7!=0)
            {
                if(brs[k]<p) {brs[k]++; br++; k=d[i].f+1;}
            }
        }
    }
    if(br==m) {cout<<"OK"<<endl; return 0;}
    br=0;
    for(i=0;i<m;i++)
    {
        for(k=d[i].s;k<=d[i].f;k++)
            if(brs2[k]<p) {brs2[k]++; br++; k=d[i].f+1;}
    }
    if(br==m) {cout<<"MIXED"<<endl; return 0;}
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
