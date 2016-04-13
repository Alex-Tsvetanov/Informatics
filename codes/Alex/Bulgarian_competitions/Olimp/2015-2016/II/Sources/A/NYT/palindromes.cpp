#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
vector<int>gr[10003];
string s;
int n,score[10003],before[10003];
void add_odd()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        j=0;
        while(i-j>=0&&i+j<n)
            if(s[i-j]==s[i+j])
            {
                gr[i-j].push_back(i+j+1);
                j++;
            }
            else break;
    }
}
void add_even()
{
    int i,j,start,fin;
    for(i=0;i<n-1;i++)
    {
        start=i;
        fin=i+1;
        j=0;
        while(start-j>=0&&fin+j<n)
            if(s[start-j]==s[fin+j])
            {
                gr[start-j].push_back(fin+j+1);
                j++;
            }
            else break;
    }
}
int bfs()
{
    int i,j,steps=0,now;
    for(i=1;i<n+1;i++)before[i]=-1;
    queue<int>nodes;
    nodes.push(0);
    while(!nodes.empty())
    {
        now=nodes.front();
        for(j=0;j<gr[now].size();j++)
            if(before[gr[now][j]]==-1)
            {
                nodes.push(gr[now][j]);
                before[gr[now][j]]=now;
                score[gr[now][j]]=score[now]+1;
            }
        nodes.pop();
    }
    return score[n];
}
int main()
{
    int i,j,start,fin;
    //freopen("generated.txt","r",stdin);
    cin>>s;
    n=s.size();
    add_odd();
    add_even();
    printf("%d\n",bfs()-1);
}
