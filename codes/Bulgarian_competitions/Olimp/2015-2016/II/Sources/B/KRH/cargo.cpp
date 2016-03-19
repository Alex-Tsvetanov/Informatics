#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct pairr
{int b;
int d;
//int vi;
};
vector<pairr> vtg[100000000];
pairr hapq[1000000];
pairr temp[1000000];
bool flag=0;
int j=0,dt,i,t,maxd,mind,p,j1;
bool cmp(pairr a,pairr c)
{if(a.b<c.b) return 1;
return 0;
}
// -1 - ERROR
// else - SUCCESS -> flag==0
int solve(int curr,int j,pairr hapq[],bool flag)
{cout<<curr<<" "<<flag<<endl;
if(curr>maxd&&j!=0) {cout<<hapq[j].d<<"laaaaaa"<<endl;return -1;}
if(curr>maxd&&j==0) return 1;
if(curr%7>4) {if(flag==0) {dt=solve(curr+2,j,hapq,flag);if(dt==1) return 1;else if(dt==-1) flag=1;};}
for(i=0;i<j;i++)
{if(hapq[i].d-curr<0) {cout<<hapq[i].d<<"lalaaa"<<endl;return -1;}
else hapq[i].b=hapq[i].d-curr;
}
if(vtg[curr].size()>0)
{for(i=0;i<vtg[curr].size();i++)
{hapq[j].d=vtg[curr][i].d;
hapq[j].b=curr-hapq[j].d;
j++;
}
sort(hapq,hapq+j,cmp);
}
if(j<=p) {j=0;return solve(curr+1,0,temp,0);}
else
{j1=0;
for(i=p;i<j;i++)
{temp[j1].d=hapq[i].d;
}
j-=p;
return solve(curr+1,j,temp,0);
}
}
int main()
{int flag=0,n,m,i;
pairr pr;
cin>>n>>m>>p;
p=p/2;
mind=n;
maxd=0;
for(i=0;i<=m-1;i++)
{cin>>pr.b>>pr.d;
pr.b--;
pr.d--;
mind=min(pr.b,mind);
maxd=max(pr.d,maxd);
//pr.vi=v[pr.b].size()+1;
vtg[pr.b].push_back(pr);
}
int r;
r=solve(mind,0,hapq,0);
if(r==-1) cout<<"IMPOSSIBLE"<<endl;
else if(r==1&&flag==1) cout<<"MIXED"<<endl;
else if(r==1&&flag==0)cout<<"OK"<<flag<<endl;
return 0;
}
