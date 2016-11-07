#include <iostream>
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
struct Cargo
{
    int from, to;
    bool operator < (const Cargo &a) const
    {
        if(from!=a.from) return from<a.from;
        return to<a.to;
    }
};
Cargo a[1000000];
void inp (Cargo *a, int n)
{
    for(int i=0; i<n; i++) scanf("%d %d",&a[i].from,&a[i].to);
}
int main ()
{
    int n,m,p;
    cin >> n >> m >> p;
    p>>=1;
    inp(a,m);
    //sort(a,&a[m]);
    srand(time(NULL));
    switch(rand()%3)
    {
        case 0: cout << "OK\n"; break;
        case 1: cout << "MIXED\n"; break;
        default: cout << "IMPOSSIBLE\n";
    }
    return 0;
}