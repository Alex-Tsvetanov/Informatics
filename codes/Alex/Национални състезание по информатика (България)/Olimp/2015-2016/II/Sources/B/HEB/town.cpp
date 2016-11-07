#include<iostream>
#include<vector>
#include<iomanip>
#include<climits>
#include<cstring>
#include<cmath>
using namespace std;
vector <int> v0[200001];
vector <int> v1[200001];
int used[400001];
int minst=500001;
void dfs(int seg,int fin,int stoin)
{
    if(seg==fin)
    {
        if(stoin<minst)minst=stoin;
        return ;
    }else
    {
        used[seg]=1;
        int n=v0[seg].size(),i;
        int m=v1[seg].size();
        for(i=0;i<n;i++)
        {
            if(used[v0[seg][i]]==0)dfs(v0[seg][i],fin,stoin);
        }
        for(i=0;i<m;i++)
        {
            if(used[v1[seg][i]]==0)dfs(v1[seg][i],fin,stoin+1);
        }
        return ;
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int i=0,n,a,b,flagst=0,flagfin=0,start,finish;
    cin>>n;
    cin>>start>>finish;
    while(cin>>a>>b)
    {
        if(a==start||b==start)flagst=1;
        if(b==finish||a==finish)flagfin=1;
        v0[a].push_back(b);
        v1[b].push_back(a);
    }
    if(flagst==0||flagfin==0)cout<<"X"<<"\n";
    else
    {
        dfs(start,finish,0);
        cout<<minst<<"\n";
    }
    return 0;
}
