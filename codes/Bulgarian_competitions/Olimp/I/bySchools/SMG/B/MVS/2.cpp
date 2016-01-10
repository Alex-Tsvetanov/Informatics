#include<iostream>
#include<vector>

using namespace std;

long p;
int m, k;

int *ways;

int main()
{
    cin>>p>>m;
    ways = new int[p+1];
    fill(ways, ways+p+1, 0);
    int cs, ce;
    for(int i = 0; i<m; i++)
    {
        cin>>cs>>ce;
        ways[cs]++;
        ways[ce]++;
    }
    cin>>k;
    vector<long> nodes;
    for(long i = 0; i<=p; i++)
    {
        if(ways[i]>=k)
            nodes.push_back(i);
    }
    cout<<nodes.size()<<endl;
    for(long i = 0; i<nodes.size(); i++)
    {
        cout<<nodes[i]<<" ";
    }
    delete[] ways;
    return 0;
}
