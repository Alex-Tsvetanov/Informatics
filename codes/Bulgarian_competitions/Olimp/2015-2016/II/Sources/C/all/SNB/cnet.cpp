#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
long long n,m;
vector<int>v[3003];
 int used[3003],a[3003];
void read()
{
    long long i,x,y;
    cin>>n>>m;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
    }
}
void BFS(int i)
{

    queue<int>q;
    q.push(i);
    used[i]=1;
    int j,nd,sz;
    while(!q.empty())
    {
        nd=q.front();
        q.pop();
        sz=v[nd].size();
        for(j=0;j<sz;j++)
        {
            if(!used[v[nd][j]])
            {
                used[v[nd][j]]=1+used[nd];
                q.push(v[nd][j]);
            }
        }
    }
}
int main()
{
    int i,j;
    long long sum=0,msum=3003*3003,br=0,p=0;
    read();
    for(i=0;i<n;i++)
    {
        memset(used,0,sizeof(used));
        BFS(i);sum=0;
        /*cout<<i<<endl;
        for(j=0;j<n;j++)
        {
            cout<<used[j]<<" ";
        }
        cout<<endl;*/
        for(j=0;j<n;j++)
        {
            if(used[j]==0)
            {
                sum=3003*3003;
                break;
            }
            sum+=used[j];
        }
        if(sum==msum)
        {
            a[br]=i;
            br++;
        }
        if(sum<msum)
        {
            msum=sum;
            br=1;
            a[0]=i;
        }
    }
    cout<<br;
    if(n<=500)
    {
        cout<<endl;
        for(i=0;i<br;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
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
7 4
4 7
*/
