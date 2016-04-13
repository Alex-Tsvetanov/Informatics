#include <bits/stdc++.h>
using namespace std;
unsigned long long k,br=0,t;
map<pair<long long,long long>, bool> mp;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>k;
    for(int n=1;;n++)
    {
        if(1+n+(2*1*n)-2*1+1>k)
        {
            break;
        }
        for(int m=1;;m++)
        {
            if(n<m)
            {
                t=m+n+(2*m*n)-2*n;
                if(t==k)
                {
                    mp[make_pair(n,m)]=true;
                }
                if(t>k)
                {
                    break;
                }
            }
            else
            {
                t=m+n+(2*m*n)-2*m+1;
                if(t==k)
                {
                    mp[make_pair(n,m)]=true;

                }
                if(t>k)
                {
                    break;
                }
            }
        }
    }

    if(mp.size()==0)
    {
        cout<<0<<"\n";
        return 0;
    }
    cout<<mp.size()<<"\n";
    map<pair<long long,long long>, bool>::iterator it;
    for(it=mp.begin();it!=mp.end();it++)
    {
        cout<<it->first.first<<" "<<it->first.second<<endl;
    }

    return 0;
}
