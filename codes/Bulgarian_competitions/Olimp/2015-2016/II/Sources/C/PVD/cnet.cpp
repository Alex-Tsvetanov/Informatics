#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

priority_queue<pair<int,int> > p;
long long res[4096],visited[4096];
vector<int> rebra[4096];
int n,m;
const long long INF=10000000;
int minsum=INF;
vector<int> rip;

void refresh()
{   for(int i=0;i<n;i++)
        {res[i]=INF;visited[i]=0;}

}

int calcsum()
{   int sum=0;
    for(int i=0;i<n;i++)
        {sum+=res[i];}
    return sum;
}

void init()
{   cin>>n>>m;
    for(int i=0;i<m;i++)
    {   int a,b;
        cin>>a>>b;
        rebra[a].push_back(b);
    }
}

void check(pair<int,int> z)
{   int pr=z.first,a=z.second;
    if(!visited[a])visited[a]=true;
    else return;
    for(int i=0;i<rebra[a].size();i++)
    {   p.push(make_pair(pr-1,rebra[a][i]));
    }
    if(res[a]>-pr)res[a]=-pr;
}

void d_extra (int a)
{   p.push(make_pair(0,a));
    while(p.size()>0)
    {   pair<int,int> d=p.top();
        p.pop();
        check(d);
    }
}


int main()
{   init();
    for(int i=0;i<n;i++)
    {   refresh();
        d_extra(i);
        int w=calcsum();
        //cout<<i<<" "<<w<<endl;
        if(w==minsum&&minsum!=INF)
        {   rip.push_back(i);

        }
        else if(w<minsum)
        {   minsum=w;
            rip.clear();
            rip.push_back(i);
        }
    }
    cout<<rip.size()<<endl;
    for(int i=0;i<rip.size();i++)
        cout<<rip[i]<<" ";
    cout<<endl;

    return 0;
}

