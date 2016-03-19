#include<iostream>
#include<queue>
using namespace std;
int net[201][201];
int m,n;
pair<int,int> findEmpty()
{
    pair<int,int> ans;
    ans.first=-1;
    ans.second=-1;
    for(int y=0; y<n; y++)
    {
        for(int x=0; x<m; x++)
        {
            if(net[x][y]==0)
            {
                ans.first=x;
                ans.second=y;
                return ans;
            }
        }
    }
    return ans;
}
int main()
{
    cin>>m>>n;
    int a;
    for(int y=0; y<n; y++)
    {
        for(int x=0; x<m; x++)
        {
            cin>>a;
            if(a==1)
            {
                a=-1;
            }
            net[x][y]=a;
        }
    }
    int ans=0;
    while(findEmpty().first>=0)
    {
        ans++;
        pair<int,int>pos=findEmpty();
        queue<pair<int,int> >obh;
        obh.push(pos);
        net[pos.first][pos.second]=ans;
        while(!obh.empty())
        {
            pair<int,int> cur,add;
            cur=obh.front();
            obh.pop();
            if(net[cur.first+1][cur.second]==0 and cur.first<m-1)
            {
                net[cur.first+1][cur.second]=ans;
                add.first=cur.first+1;
                add.second=cur.second;
                obh.push(add);
            }
            if(net[cur.first-1][cur.second]==0 and cur.first>0)
            {
                net[cur.first-1][cur.second]=ans;
                add.first=cur.first-1;
                add.second=cur.second;
                obh.push(add);
            }
            if(net[cur.first][cur.second+1]==0 and cur.second<n-1)
            {
                net[cur.first][cur.second+1]=ans;
                add.first=cur.first;
                add.second=cur.second+1;
                obh.push(add);
            }
            if(net[cur.first][cur.second-1]==0 and cur.second>0)
            {
                net[cur.first][cur.second-1]=ans;
                add.first=cur.first;
                add.second=cur.second-1;
                obh.push(add);
            }

        }
    }
    cout<<ans<<endl;
    return 0;
}
