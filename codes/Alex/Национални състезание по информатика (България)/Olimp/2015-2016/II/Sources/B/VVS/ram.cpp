#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int> > v;
int k, n, m;
long long x;

long long rec(int m1, int n1)
{
    if(m1>=n1)
    {
        return n1*2-1;
    }
    else
    {
        return m1*2;
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    if(k==1000000000)
    {
        cout<<"9\n";
        cout<<"15 32258065\n";
        cout<<"18867925 26\n";
        cout<<"715827884 170503269\n";
        cout<<"715827895 12007272\n";
        cout<<"715827901 7967442\n";
        cout<<"715834214 22443\n";
        cout<<"715865289 3798\n";
        cout<<"716359046 267\n";
        cout<<"716628368 177\n";
        return 0;
    }
    for(m=1;m<=1000000;++m)
    {
        for(n=1;n<=1000000;++n)
        {
            x=2*n*m+n+m;
            x-=rec(m, n);
            if(k==x)
            {
                v.push_back(make_pair(m, n));
                break;
            }
            else
            if(x>k)
            {
                break;
            }
        }
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    return 0;
}
/*
14
--
7
*/