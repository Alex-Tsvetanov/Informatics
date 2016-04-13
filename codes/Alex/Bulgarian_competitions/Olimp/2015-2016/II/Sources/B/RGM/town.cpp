#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
struct fff
{
    int k,d;
};
int used[200002];
vector<int> from[200002];
vector<int> to[200002];
priority_queue <fff> pq;
fff h;
bool operator < (const fff A, const fff B)
{
    return A.d>B.d;
}
int main ()
{
    int n;
    int p,q,a,b;
    cin>>n;
    cin>>a>>b;
    int bra=0, brb=0;
    while (cin>>p>>q)
    {
        if (p==a || q==a) {bra++;}
        if (p==b || q==b) {brb++;}
        from[p].push_back(q);
        to[q].push_back(p);
    }
    if (bra==0 || brb==0) {cout<<"X"<<endl; return 0;}

    h.k=a;
    h.d=0;
    pq.push(h);
    fff f;
    while (!pq.empty())
    {
        f=pq.top();
        pq.pop();
        if (f.k==b) {cout<<f.d<<endl; break;}

        if (used[f.k]==0)
        {
            used[f.k]=1;

            for (int i=0; i<from[f.k].size(); i++)
            {
                h.k=from[f.k][i];
                h.d=f.d;
                pq.push(h);
            }

            for (int i=0; i<to[f.k].size(); i++)
            {
                h.k=to[f.k][i];
                h.d=f.d+1;
                pq.push(h);
            }
        }
    }
    return 0;
}
