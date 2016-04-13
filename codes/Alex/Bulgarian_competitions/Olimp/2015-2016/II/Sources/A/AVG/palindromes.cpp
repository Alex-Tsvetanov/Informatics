#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
string s;
vector <int> v[20000];
queue <int> q;
int used[20000];
bool check_for_pali(int l,int r)
{
    while(l<r)
    {
        if(s[l]!=s[r])return false;
        l++;
        r--;
    }
    return true;
}
int bfs(int e)
{
    int sz;
    int x=-1;
    q.push(x);
    while(!q.empty())
    {
        x=q.front();
       // cout<<x<<'\n';
        q.pop();
        if(x>=e)break;
        sz=v[x].size();
        for(int i=0;i<sz;i++)
        {
            if(x==-1)
            {
                q.push(v[x][i]);
                used[v[x][i]]=1;
            }
            else if(used[v[x][i]]>used[x]+1||used[v[x][i]]==0)
            {
                q.push(v[x][i]);
                used[v[x][i]]=used[x]+1;
            }
        }
    }
    /*for(int i=0;i<e+3;i++)
    {
        cout<<used[i]<<" ";
    }cout<<'\n';*/
    return used[e]-2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(check_for_pali(j,i))
            {
                //cout<<j<<" "<<i+1<<'\n';
                v[j].push_back(i+1);
            }
        }
    }
    v[-1].push_back(0);
    cout<<bfs(sz)<<'\n';
    return 0;
}
