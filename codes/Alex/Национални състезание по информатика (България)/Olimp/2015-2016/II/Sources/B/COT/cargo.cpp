#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
int n,m,p,br[100000000],minN,maxN;
pair<int, int> a[1000000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>p;
    p/=2;
    for (int i=0; i<m; i++)
    {
        cin>>a[i].first>>a[i].second;
        minN=min(minN,min(a[i].first,a[i].second));
        maxN=max(maxN,max(a[i].first,a[i].second));
    }
    sort(a,a+m);
    if (n>=100000000)
    {
        for (int i=0; i<m; i++)
        {
            for (int j=a[i].first; j<=a[i].second; j++)
                if (br[j]<p && j%7!=0 && j%7!=6)
                {
                    br[j]++;
                    swap(a[i],a[m-1]);
                    m--;
                    if (m==0)
                    {
                        cout<<"OK\n";
                        return 0;
                    }
                }
        }
        for (int i=0; i<m; i++)
        {
            bool flag=true;
            for (int j=a[i].first; j<=a[i].second; j++)
                if (br[j]<p)
                {
                    br[j]++;
                    swap(a[i],a[m-1]);
                    m--;
                    flag=false;
                    if (m==0)
                    {
                        cout<<"MIXED\n";
                        return 0;
                    }
                }
            if (flag)
                break;
        }
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    else
    {
        for (int i=minN; i<=maxN; i++)
        {
            if (i%7==6 || i%7==0)
                continue;
            int z=p;
            for (int j=0; j<m; j++)
                if (a[j].first<=i && i<=a[j].second)
                {
                    swap(a[m-1],a[j]);
                    m--;
                    z--;
                    if (z==0)
                        break;
                }
            if (m==0)
                break;
        }
        if (m==0)
        {
            cout<<"OK\n";
            return 0;
        }
        while (minN%7!=6)
            minN++;
        for (int i=minN; i<=maxN; i+=7)
        {
            int z=p;
            for (int j=0; j<m; j++)
                if (a[j].first<=i && i<=a[j].second)
                {
                    swap(a[m-1],a[j]);
                    m--;
                    z--;
                    if (z==0)
                        break;
                }
            if (m==0)
                break;
            i++;
            z=p;
            for (int j=0; j<m; j++)
                if (a[j].first<=i && i<=a[j].second)
                {
                    swap(a[m-1],a[j]);
                    m--;
                    z--;
                    if (z==0)
                        break;
                }
            if (m==0)
                break;
        }
        if (m==0)
        {
            cout<<"MIXED\n";
            return 0;
        }
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}

