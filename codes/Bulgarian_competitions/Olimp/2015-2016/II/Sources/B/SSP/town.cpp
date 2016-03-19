#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const long long inf=1000000000, Max=200001;
long long label[Max], pred[Max], i=0, u;
bool perm[Max];
struct Path
{
    int from, to;
    long long val;
    Path (int f, int t, long long v=0): from(f), to(t), val(v) {}
    bool operator < (const Path &a) const
    {
        if(from!=a.from) return from<a.from;
        return to<a.to;
    }
};
set <Path> s;
void inp ()
{
    int u,v;
    while(1)
    {
        int t=scanf("%d%d",&u,&v);
        if(t<0) break;
        s.insert(Path(u,v,1));
        s.insert(Path(v,u,100001));
    }
}

long long len(int u, int v)
{
    set<Path>::iterator it=s.find(Path(u,v));
    if(it!=s.end()) return it->val;
    return inf;
}

void init (int n, int s)
{
    label[s]=0;
    perm[s]=1;
    pred[s]=s;
    for(int v=1; v<=n; v++)
    {
        if(v==s) continue;
        label[v]=inf;
        perm[v]=0;
        pred[v]=v;
    }
    u=s;
}
void next (int n)
{
    i++;
    long long M;
    for(int v=1; v<=n; v++)
    {
        if(perm[v]) continue;
        M=min(label[v],label[u]+len(u,v));
        if(M<label[v]) {label[v]=M; pred[v]=u;}
    }
    long long min=inf, z=0;
    for(int v=1; v<=n; v++)
    {
        if(perm[v]) continue;
        if(label[v]<min) min=label[v], z=v;
    }
    perm[z]=1;
    u=z;
}

int main ()
{
    int n,a,b;
    cin >> n >> a >> b;
    inp();
    init(n,a);
    while(i<n-1) next(n);
    if(!label[b] || label[b]==inf) {cout << "X\n"; return 0;}
    cout << label[b]/100001 << endl;
    return 0;
}
