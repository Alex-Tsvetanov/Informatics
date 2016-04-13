#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

vector<int>gr[100],gr1[100];

int used[100],used1[100],q=0;

int main()
{
    queue<int> dfs;
    int n,from,to,q,p,i,f=0;
    scanf("%d %d %d",&n,&from,&to);

    int a,b;

    while(cin>>a>>b)
    {
        gr[a-1].push_back(b-1);
        gr1[a-1].push_back(b-1);
        gr1[b-1].push_back(a-1);
    }

    int node=from-1,br=0;

    if(gr1[from-1].size()==0)printf("X\n");
    else
    {
        node=from-1;
        dfs.push(from-1);
        while(f==0)
        {
                while(!dfs.empty())
                    {
                        node=dfs.front();
                        if(used[node]==0)
                        {
                            used[node]=1;
                            used1[node]=1;
                            for(i=0;i<gr[node].size();i++)dfs.push(gr[node][i]);
                        }
                        if(node+1==to){printf("%d\n",br);f=1;}
                        dfs.pop();
                    }
                for(i=0;i<gr1[node].size();i++)if(used1[gr1[node][i]]==0 and f==0 and q==0){dfs.push(gr1[node][i]),br++;q=1;}
                for(i=0;i<gr1[node].size();i++)if(used1[gr1[node][i]]==0 and gr1[node][i]==to-1){br++;printf("%d\n",br);f=1;}
                q=0;

        }
    }
}
