#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,a[3001][3001],br[3000];

int BFS1(int p)
{
    int k,i,steps=0;
    queue <int> q;
    bool used[3001];
    
    for(i=0;i<n;i++)
    {
        used[i]=0;
    }
    
    used[p]=1;
    q.push(p);
    
    while(!q.empty())
    {
        
        k=q.front();
        q.pop();
        
        for(i=0;i<br[k];i++)
        {
            if(used[a[k][i]]==0)
            {
                q.push(a[k][i]);
                used [a[k][i]]=1;
            }
        }
        
        steps++;
    }
    
    for(i=0;i<n;i++)
    {
        if(used[i]==0)return -1;
    }
    
    return steps;
}

int BFS2(int p)
{
    int k,i,steps=0;
    queue <int> q;
    bool used[3001];
    
    for(i=0;i<3001;i++)
    {
        used[i]=0;
    }
    
    used[p]=1;
    q.push(p);
    
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        
        for(i=0;i<br[k];i++)
        {
            if(used[a[k][i]]==0)
            {
                 q.push(a[k][i]);
                 used [a[k][i]]=1;
            }
        }
        
        steps++;
    }
    
    return steps;
}


int main ()
{
    int i,x,y,mini,res[3001],br2;
    
    cin>>n>>m;
    
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        
        a[x][br[x]]=y;
        br[x]++;
    }
    
    x=BFS1(0);
    
    mini=x;
    res[0]=x;
    br2=1;
    
    for(i=1;i<n;i++)
    {
        x=BFS1(i);
        
        if(x==mini)
        {
            res[br2]=i;
            br2++;
        }
        if((x<mini && x!=-1) || mini==-1)
        {
            mini=x;
            res[0]=i;
            br2=1;
        }
    }
    
    sort(res,res+br2);
    
    cout<<br2<<endl;
    
    for(i=0;i<br2-1;i++)
    {
        cout<<res[i]<<" ";
    }
    
    cout<<res[br2-1]<<endl;
    
    return 0;
}