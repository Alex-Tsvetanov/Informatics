#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
vector <int> edges[3001];
queue <int> q;
queue <int> waves;
int minw[3001],vis[3001]={0},mintime=500002,br,viable[3001]={0},k,ans=0,masans[3001],ansi=0;
int main()
{
    int n,m,maxw,mini=0,i,x,y,j;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        scanf("%d",&y);
        edges[x].push_back(y);
    }
    for(i=0;i<n;i++)
        minw[i]=500001;
    for(i=0;i<n;i++)
    {
        if(viable[i]==1)
         continue;
        br=1;
        maxw=0;
        q.push(i);
        waves.push(0);
        vis[i]=1;
        while(!(q.empty()))
        {
            x=q.front();
            y=waves.front();
            for(k=0;k<edges[x].size();k++)
            {
                if(vis[edges[x][k]]==0)
                {
                    vis[edges[x][k]]=1;
                    q.push(edges[x][k]);
                    waves.push(y+1);
                    br++;
                }
                if(y+1<minw[edges[x][k]])
                    minw[edges[x][k]]=y+1;
            }
            q.pop();
            waves.pop();
        }
        if(br==n)
        {
         for(j=0;j<n;j++)
         {
             if(minw[j]>maxw)
                maxw=minw[j];
         }
         if(maxw<mintime)
         {
             mini=i;
             mintime=maxw;
             ans=1;
             masans[ans]=i;
         }
         else
         if(maxw==mintime)
         {
             ans++;
             masans[ans]=i;
         }
        }
        if(br!=n)
        {
         for(j=0;j<n;j++)
         {
          if(vis[j]==1)
            viable[j]=1;
         }
        }
        for(j=0;j<n;j++)
        {
            minw[j]=500001;
            vis[j]=0;
        }
    }
    cout<<ans<<endl;
    for(i=1;i<ans;i++)
        cout<<masans[i]<<" ";
    cout<<masans[ans]<<endl;
    return 0;
}


/*


8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
4 7
7 4


*/
