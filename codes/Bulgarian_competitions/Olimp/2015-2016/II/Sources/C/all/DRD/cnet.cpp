#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector <int> g[3005],p[3005];
vector <int> ans;
int vis[3005],q[3005];

void BFS(int v)
{
 int i,ukbeg=0,ukend=1,k;

 vis[v]=1;
 q[0]=v;

  while(ukbeg<ukend)
  {
   k=q[ukbeg];

    for(i=0;i<g[k].size();i++)
    {
     if(vis[g[k][i]]==0)
     {
      q[ukend]=g[k][i];
      p[k][i]=1;
      vis[g[k][i]]=1;
      ukend++;
     }
    }
   ukbeg++;
  }
}

int main()
{

int n,m,u,v,i,j,sz,k;
bool sol;

scanf("%d%d",&n,&m);

 for(i=1;i<=m;i++)
 {
  scanf("%d%d",&u,&v);
  g[u].push_back(v);
  p[u].push_back(0);
 }

 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
   vis[j]=0;

  for(j=0;j<n;j++)
   for(k=0;k<p[j].size();k++)
    p[j][k]=0;

  BFS(i);

  /*for(j=0;j<n;j++)
   cout<<vis[j]<<" ";

  cout<<endl;*/

  sol=true;
   for(j=0;j<n;j++)
    if(vis[j]==0)
    {
     sol=false;
     break;
    }

   if(sol)
    ans.push_back(i);
 }

sz=ans.size();

printf("%d\n",sz);

 for(i=0;i<sz-1;i++)
  printf("%d ",ans[i]);

 if(sz>0)
  printf("%d\n",ans[sz-1]);

return 0;
}
