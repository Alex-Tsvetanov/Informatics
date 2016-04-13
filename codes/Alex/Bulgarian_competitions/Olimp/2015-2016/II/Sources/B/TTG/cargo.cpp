#include<iostream>
using namespace std;

int main()
{
    int n,m,p;
    int s,e;
    cin>>n>>m>>p;
    for(int i=0;i<m;i++)cin>>s>>e;
    int t=n%4;
    if(!t)cout<<"MIXED\n";
    else if(t==1)cout<<"IMPOSSIBLE\n";
    else cout<<"OK\n";
    return 0;
}