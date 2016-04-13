#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<queue>
using namespace std;
vector<int>susedi[400002];
struct vruh
{
    int a, v;
};
vruh r[400002];
bool operator <(vruh x, vruh y)
{
    return x.v>y.v;
}
map< pair<int, int>, int > cena;
int put[400002];
bool obhodeni[400002];
int dijkstra(int s)
{
    priority_queue<vruh> q;
    vruh A;
    A.a=s;
    A.v=0;
    q.push(A);
    put[A.a]=0;
    obhodeni[A.a]=1;
    while(!q.empty())
    {
        vruh curr=q.top();
        q.pop();
        obhodeni[curr.a]=1;
        for(int i=0;i<susedi[curr.a].size();i++)
        {
            if(!obhodeni[susedi[curr.a][i]] && put[susedi[curr.a][i]]>put[curr.a]+cena[make_pair(curr.a, susedi[curr.a][i])])
            {
                put[susedi[curr.a][i]]=put[curr.a]+cena[make_pair(curr.a, susedi[curr.a][i])];
                vruh o;
                o.a=susedi[curr.a][i];
                o.v=put[susedi[curr.a][i]];
                q.push(o);
            }
        }

    }

}
int main(){
int n, x, y, m=0;
cin>>n>>x>>y;
while(cin)
{
    int a, b;
   cin>>a>>b;
   susedi[a].push_back(b);
   susedi[b].push_back(a);
   cena[make_pair(a,b)]=0;
   cena[make_pair(b,a)]=1;
   m++;
}
m--;
//cout<<m<<endl;
for(int i=0;i<=n;i++)
{
    put[i]=1000000000;
}
dijkstra(x);

if(!obhodeni[y])
    cout<<"X\n";
else
cout<<put[y]<<endl;
/// izglejda raboteshto, testvano e super malko
return 0;
}
