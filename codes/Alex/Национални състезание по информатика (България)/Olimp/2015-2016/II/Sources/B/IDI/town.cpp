#include<iostream>
#include<queue>
using namespace std;
int razst[200001];
vector<int> susedi[200001];
vector<int> cena[200001];
struct num
{
    int x;
    num(){};
    num(int a)
    {
        x=a;
    }
};
bool operator<(num a,num b)
{
    return razst[a.x]>razst[b.x];
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
    {
        razst[i]=1<<30;
    }
    int x,y;
    while(cin>>x)
    {
        cin>>y;
        susedi[x].push_back(y);
        cena[x].push_back(0);
        susedi[y].push_back(x);
        cena[y].push_back(1);
    }
    priority_queue<num> q;
    razst[a]=0;
    q.push(num(a));
    while(!q.empty())
    {
        x=q.top().x;
        q.pop();
        if(x==b)
        {
            cout<<razst[x]<<"\n";
            return 0;
        }
        for(int i=0;i<susedi[x].size();i++)
        {
            if(razst[susedi[x][i]]>razst[x]+cena[x][i])
            {
                razst[susedi[x][i]]=razst[x]+cena[x][i];
                q.push(susedi[x][i]);
            }
        }
    }
    cout<<"X\n";
    return 0;
}
