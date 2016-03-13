#include<iostream>
using namespace std;
unsigned int matrix[10001][10001],n,m,maxWidth;
bool visited[10001];
void dfs(unsigned int node,unsigned int curWidth)
{
    if(node==n)
    {
        if(maxWidth<curWidth) maxWidth=curWidth;
        return;
    }
    visited[node]=true;
    for(int i=1;i<=n;++i)
    {
        if(!visited[i] && matrix[node][i]>0)
        {
            //cout<<"Node: "<<node<<" current width: "<<curWidth<<" width from "<<node<<" to "<<i<<" is "<<matrix[node][i]<<endl;
            dfs(i,curWidth<matrix[node][i] ? curWidth:matrix[node][i]);
        }
    }
    visited[node]=false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int a,b,w;
        cin>>a>>b>>w;
        matrix[a][b]=matrix[b][a]=w;
    }
    dfs(1,65001);
    cout<<maxWidth<<endl;
    return 0;
}
