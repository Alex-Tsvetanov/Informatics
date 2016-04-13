#include<iostream>
#include<algorithm>
using namespace std;

struct zaqvka
{
    int s, e;
};

int n, m, p, maxe, mins;
zaqvka z[10010];
bool neigh[10010][10010];

bool cmp(zaqvka a, zaqvka b) { return (a.e > b.e); }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(); cout.tie();

    cin >> n >> m >> p;
    cin >> z[0].s >> z[0].e;
    mins = z[0].s; maxe = z[0].e;

    if((z[0].e-z[0].s) == 1)
    {
        neigh[z[0].s][z[0].e] = 1;
        neigh[z[0].e][z[0].s] = 1;
    }
    else
    {
        for(int j = z[0].s; j < z[0].e; j ++)
        {
            neigh[j+1][j] = 1;
            neigh[j][j+1] = 1;
        }
    }

    for(int i = 1; i < m; i ++)
    {
        cin >> z[i].s >> z[i].e;

        if(z[i].e > maxe) maxe = z[i].e;
        if(z[i].s < mins) mins = z[i].s;

        if((z[i].e-z[i].s) == 1)
        {
            neigh[z[i].s][z[i].e] = 1;
            neigh[z[i].e][z[i].s] = 1;
        }
        else
        {
            for(int j = z[i].s; j < z[i].e; j ++)
            {
                neigh[j+1][j] = 1;
                neigh[j][j+1] = 1;
            }
        }
    }

    sort(z, z+m, cmp);

    bool impossible = false, mixed = false;
    for(int i = 0; i < m; i ++)
    {
        for(int j = z[i].s; j < z[i].e; j++)
            if(neigh[j][j+1] == 0) {impossible = true; break;}
        if(impossible == true) break;

        if(z[i].e%6 == 0 || z[i].e%7 == 0) mixed = true;
        if(impossible == true) break;
        for(int j = mins; j <= maxe; j ++)
            if(neigh[z[i].e][j] == 1) {neigh[z[i].e][j] = 0; neigh[j][z[i].e] = 0;}
    }

    if(impossible == true) cout << "IMPOSSIBLE\n";
    else if(mixed == true) cout << "MIXED\n";
    else cout << "OK\n";

return 0;
}
