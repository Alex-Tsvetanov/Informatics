#include <iostream>
#define MAKS 200000
using namespace std;
int A[15000][15000];
int B[15000][15000];
int br=0;
int c=0;
int All_Ways[MAKS];
int N,_a,_b;
int visited[MAKS];
void dfs(int node);
bool Game_Over = true;
bool Game_Over2 = true;
bool Change = true;
int container[MAKS];
int i_container=0;
int Foul[MAKS];
int main ()
{
    int n,a,b;
    cin>>n>>a>>b;
    N=n;
    _a=a;
    _b=b;
    int p[MAKS],q[MAKS];
    for (int i=0; cin; i++)
    {
        cin>>p[i]>>q[i];
        if (p[i]==a or q[i]==a) Game_Over=false;
        if (p[i]==b or q[i]==b) Game_Over2=false;
    }
    if (Game_Over or Game_Over2) cout<<"X"<<endl;
    else
    {
        for (int i=0; i<n; i++)
        {
            A[p[i]-1][q[i]-1]=1;
            A[q[i]-1][p[i]-1]=1;
        }
        for (int i=0; i<n; i++)
        {
            B[p[i]-1][q[i]-1]=1;
        }
        while(Change)
        {
            br=0;
            dfs(a-1);
            Change=false;
                for (int i=0; i<n; i++)
                {
                    if (visited[i]==1) visited[i]=0;
                }
                for (int i=0; i<i_container; i++)
                {
                    if (A[a-1][container[i]]!=2)
                    {
                        A[a-1][container[i]]=2;
                        Change=true;
                    }
                }
        }
        if (c==0) cout<<"X"<<endl;
        else
        {
            for (int i=0; i<c-1; i++)
            {
                for (int j=0; j<c-1; j++)
                {
                    if (Foul[j]>Foul[j+1])
                    {
                        swap(Foul[j],Foul[j+1]);
                    }
                }
            }
        }
        cout<<Foul[0]<<endl;
    }
    return 0;
}
void dfs(int node)
{
    visited[node]=1;
    for (int i=0; i<N; i++)
    {
        if (A[node][i]==1 and !visited[i] and i+1!=_b and visited[i]!=2 and node==_a-1)
        {
           if (B[node][i]==0) Foul[c]++;
            container[i_container]=i;
            i_container++;
            br++;
            dfs(i);
        }
        if (A[node][i]==1 and !visited[i] and i+1!=_b)
        {
           if (B[node][i]==0) Foul[c]++;
            br++;
            dfs(i);
        }
        if (A[node][i]==1 and !visited[i] and i+1==_b)
        {
            if (B[node][i]==0) Foul[c]++;
            br++;
            All_Ways[c]=br;
            c++;
            br--;
        }
        if (A[node][i]==1 and !visited[i] and i+1==_b and visited[i]!=2 and node==_a-1)
        {
            if (B[node][i]==0) Foul[c]++;
            container[i_container]=i;
            i_container++;
            br++;
            All_Ways[c]=br;
            c++;
            br--;
        }
    }
    br--;
}
