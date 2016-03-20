#include<cstring>
#include<queue>
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int br[4096],minbr=400000;
vector<int> susedmatr[4096];vector<int> comp;
int ostrov,put,nachalo,par[4096];
int poseten[4096];
void BFS(int node)
{
    queue<int> q;
    q.push(node);
    poseten[node]=1;
    while(!q.empty())
    {
        cout<<1<<endl;
        node=q.front();
        q.pop();
        for(int i=0; i<susedmatr[node].size(); i++)
            if(!poseten[susedmatr[node][i]])
            {
                par[susedmatr[node][i]]=node;
                poseten[susedmatr[node][i]]=1;

                q.push(susedmatr[node][i]);
            }
    }
    for(int i=0;i<ostrov;i++)
    {
        if(poseten[node]==0)return;
    }
    comp.push_back(node);
}
void read()
{
    int x,y;
    cin>>ostrov>>put;
    for(int i=0; i<put; i++)
    {
        cin>>x>>y;
        susedmatr[x].push_back(y);
    }

}
int main()
{
    vector<int> beg;
    read();
    for(int i=0;i<ostrov;i++)
    {
        BFS[i];
    }
    sort(comp.begin(),comp.end());
    int sz=comp.size();
    cout<<sz<<endl;
    for(int i=0;i<sz;i++)
        cout<<comp[i]<<" ";
    cout<<endl;
    return 0;
}/* 8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
7 4
4 7
*/
