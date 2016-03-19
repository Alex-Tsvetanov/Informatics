#include<iostream>
using namespace std;

const int MAX=200000;
const int inf=1000000000;
int w[MAX/18][MAX/18];
int LABEL[MAX],n,a,b;///n s end
bool PERM[MAX];

void Init()
{
    PERM[a]=1;LABEL[a]=0;
    for(int i=1;i<=n;i++)if(!PERM[i])LABEL[i]=inf;
}

void Inp(int &u)
{
    int v;
    cin>>n>>a>>b;///n k s
    for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
      w[i][j]=inf;
    for(int i=1;i<=n;i++)w[i][i]=0;
    while(!cin.eof())
    {
        cin>>u>>v;
        w[u][v]=0;
        w[v][u]=1;
    }
    u=a;
    Init();
}

void ShowW()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)if(w[i][j]>=inf)cout<<(char)236<<' ';else cout<<w[i][j]<<' ';
        cout<<endl;
    }
}

void MakeNext(int &u)
{
    int M;
    for(int v=1;v<=n;v++)
    {
        if(PERM[v])continue;
        M=min(LABEL[v],LABEL[u]+w[u][v]);
        if(M<LABEL[v])LABEL[v]=M;
    }
    int min=inf;
    for(int v=1;v<=n;v++)
    {
        if(PERM[v])continue;
        if(LABEL[v]<min){min=LABEL[v];u=v;}
    }
    PERM[u]=1;
}

int main()
{
    int u,i=0;
    Inp(u);
//ShowW();
    while(i<n-1){MakeNext(u);i++;}
    if(LABEL[b]>=inf){cout<<'X'<<endl;return 0;}
    cout<<LABEL[b]<<endl;
}