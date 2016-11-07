#include <queue>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct node
{
    vector <int> list;
};
struct graph
{
    node a[10001];
};
 graph g;
int used[10001];
queue <int> q;
int n;
string s;
int ans(int v)
{
    used[v]=1;
    int br=0;
    q.push(v);
    while(!q.empty())
    {
        int size1=q.size();
        for(int i=0;i<size1;i++)
        {
            int y=q.front();
            q.pop();
            for(int j=0;j<g.a[y].list.size();j++)
            {
                int x=g.a[y].list[j];
                if(!used[x])
                {
                    q.push(x);
                    used[x]=1;

                }
            }
        }
        br++;
        if(used[n]==1)
            return br;
    }
}
int main()
{
    ///freopen("input.txt","r",stdin);

    cin>>s;
    n=s.length();
    for(int i=0;i<n;i++)
    {
        int start=i,end=i;
        while(start>=0&&end<n&&s[start]==s[end])
        {
            g.a[start].list.push_back(end+1);
            start--;
            end++;
        }
        start++;
        end--;
    }
    for(int i=0;i<n-1;i++)
    {
        int start=i,end=i+1;
        while(start>=0&&end<n&&s[start]==s[end])
        {
            g.a[start].list.push_back(end+1);
            start--;
            end++;
        }
        start++;
        end--;
    }
    cout<<ans(0)-1<<endl;
}
