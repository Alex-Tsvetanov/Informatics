#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int p, m;
    cin >> p;
    cin >> m;
    int r[m][2], a, b, k, town[p];
   for (int i = 0; i<m;i++)
    {
cin >> a;
cin >> b;
r[i][1] = a; r[i][2] = b;
town[a] = 0; town[b] = 0;
    }cin>>k;
    int z, x, g=0, newarr[p];
   
    for(int i = 0; i<m; i++) 
    {
        z=r[i][1];x=r[i][2];
        town[z]+= 1;town[x]+= 1;
        if (town[z]==k) 
        {
            newarr[g]=z;
            g++;
        }
        if (town[x]==k) 
        {
            newarr[g]=x;
            g++;
        }
    }
    cout<<g<<'\n';
    sort(newarr,newarr + g);
    for (int i=0; i<g;i++) {
        cout<<newarr[i]<<" ";
    }
    cout<<'\n';
    return 0;
} 