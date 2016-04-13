#include<iostream>
#include<vector>
using namespace std;
long long n,m,p,mas[1000001],x,y,flag,used[1000001];
vector <pair <long long, long long> > v,v1;

int main()
{
    cin>>n>>m>>p;
    p/=2;
    //cout<<n%7<<endl;
    for(int i=1; i<=m; i++)
    {
        cin>>x>>y;

        if(used[x]==0)used[x]=1;
        else if(used[x]==1)
        {
            v.push_back(make_pair(x+1,1));
        }
        v.push_back(make_pair(y,-1));
    }
    for(int i=0; i<v.size(); i++)
    {
        if(v[i].second==1)
        {
            p--;
        }
        if(v[i].second==-1)
        {
            p++;
            if(v[i].first%7==0||v[i].first%6==0)
            {
                flag=1;

            }
        }
        if(p<0)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }
    }
    if(flag==1)
    {
        cout<<"MIXED"<<endl;
        return 0;
    }
    cout<<"OK"<<endl;
    return 0;
}
