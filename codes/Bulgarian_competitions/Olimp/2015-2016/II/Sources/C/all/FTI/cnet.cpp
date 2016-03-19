#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
vector<long long int>v[3000],z;
queue<long long int>q;
long long int used[3000],nodb[3000],br,k;
int BFS(int i)
{
    long long int sz,t,j,nb,vr=0;
    used[i]=1;
    q.push(i);
    vr++;
    while(!q.empty())
    {
         t=q.front();
         q.pop();
         sz=v[t].size();
         for(j=0;j<sz;j++)
         {
             nb=v[t][j];
             if(!used[nb])
             {
                 vr++;
                 used[nb]=used[t]+1;
                 q.push(nb);
             }
         }
    }
    return vr;
}
int main()
{
    long long int i,x,y,n,m;
     cin>>n>>m;
     for(i=0;i<m;i++)
     {
         cin>>x>>y;
         v[x].push_back(y);
     }
     for(i=0;i<n;i++)
     {
        k=BFS(i);
        if(k==n)
        {
            br++;
            z.push_back(i);
        }
        memset(used,0,sizeof(used));
     }
    cout<<br<<endl;
    cout<<z[0];
    for(i=1;i<z.size();i++)
    {
        cout<<" "<<z[i];
    }
    cout<<endl;
}
