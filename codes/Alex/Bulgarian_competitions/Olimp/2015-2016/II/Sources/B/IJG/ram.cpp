#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
long long k, br, x, y, n;
vector < pair <long long, long long> > v;
int main ()
{
    cin>>k;
    for (int m=1; m<=k; m++)
    {
       x=abs(m-k+1);
       y=abs(1-2*m);
       if (x%y==0 && (x!=0 && y!=0) && m>=x/y)
       {
           n=x/y;
           br++;
           v.push_back(make_pair(m, n));
       }

       x=m+k;
       y=2*m+1;
       if (x%y==0 && x!=0 && y!=0 && m<x/y)
       {
           n=x/y;
           br++;
           v.push_back(make_pair(m, n));
       }
    }
    cout<<br<<endl;
    for (int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<endl;

    return 0;
}
