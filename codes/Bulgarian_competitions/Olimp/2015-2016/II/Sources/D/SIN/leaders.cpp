#include<iostream>
#include<algorithm>
using namespace std;
int n,k;

struct ch
{
    int chislo;
    int red;
}masif[1000001];

bool f (ch a, ch b)
{
    if (a.chislo>b.chislo) return true;
    else if (a.chislo<b.chislo) return false;
    else if (a.chislo==b.chislo && a.red>b.red) return true;
    else if (a.chislo==b.chislo && a.red<b.red) return false;
}

int main ()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>masif[i].chislo;
        masif[i].red=i;
    }
    sort (masif+1 , masif+n+1 , f);
    for (int i=1;i<=n;i++)
    {
        if (masif[i].red>k)
        {
            k=masif[i].red;
            cout<<masif[i].chislo<<' ';
        }
        if (n==k) break;
    }
    cout<<endl;
    return 0;
}
// 7 50 1 40 2 3 4 30
