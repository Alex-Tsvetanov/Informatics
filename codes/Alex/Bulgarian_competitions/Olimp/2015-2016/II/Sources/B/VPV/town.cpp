#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

struct prior
{
   bool operator()(pair<int,int> & l, pair<int,int> & r)
   {
       return l.first >= r.first;
   }
};
long long INF=1000000000;
int pos[400005], dj[400005];
 vector < pair < int , int > >  v[400000];


int main ()
{
    int n;
    int a,b;
    int x,y;
    cin>>n>>a>>b;
    for (int i=0;i<=n;i++)
        dj[i]=INF;

    while(cin>>x)
    {
        cin>>y;
        v[x].push_back(make_pair(y,0));
        v[y].push_back(make_pair(x,1));
    }


    int ko,m,t;
    pair <int, int> p;
    priority_queue < pair < int , int > , vector < pair < int , int > > , prior > q;
    q.push(make_pair(0,a));
    pos[a]=1;
    dj[a]=0;
    while (!q.empty())
    {
        p=q.top();
        q.pop();
        pos[p.second]=true;
        ko=v[p.second].size();
        for (int i=0;i<ko;i++)
        {
            m=v[p.second][i].first;
            t=v[p.second][i].second;
            if (!pos[m])
            {
                if (dj[m]>p.first+t)
            {
                    dj[m]=p.first+t;
            }
                q.push(make_pair(dj[m],m));
            }
        }
    }


    if(dj[b]==INF)cout<<"X"<<endl;
       else cout<<dj[b]<<endl;


    return 0;
}
