#include<iostream>
#include<algorithm>
using namespace std;
int n,m,paths[10000],bp=0;
int g=0,maxnu;
int tochka[500][500];
bool graph[500][500];
void findPath(int point)
{
    bool z=false;
    for(int i=1; i<n+1; i++)
    {
        if(graph[point][n]==true)
        {
            z=true;
            g=g+1;
            findPath(n);
        }

    }
    if(!z)
    {
        paths[bp] = g;
        bp = bp + 1;

    }

}
int main()
{
    cin>>n>>m;
    maxnu = 2*m;
    for(int y=0; y<m; y++)
    {
        for(int x=0; x<2; x++)
        {
            cin>>tochka[x][y];
        }
        graph[tochka[0][y]][tochka[1][y]] = true;
    }
    for(int x=0; x<2; x++)
    {
        for(int y=0; y<4; y++)
        {
            findPath(tochka[x][y]);
        }
    }

    sort(paths+0,paths+bp);
    cout<<maxnu - paths[bp]/2<<endl;


    return 0;
}
