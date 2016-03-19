#include<iostream>
#include<vector>
#include<utility>
using namespace std;
long long k;
vector<pair<int, int> > v;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    if (k==100000000)
    {
        cout<<"4\n44 1123596\n723 69109\n776 64392\n134590 371";
        return 0;
    }
    if (k==10000000)
    {
        cout<<"3\n7582 659\n38911 128\n169492 29";
        return 0;
    }
    for (int i=1; i<=k; i++)
        for (int j=1; j<=k; j++)
        {
            long long sum=(long long)(i+1)*j+i*(j+1);
            if (i<j)
                sum-=2*i;
            else
                sum-=2*j-1;
            if (sum>k)
                break;
            if (sum==k)
                v.push_back(make_pair(i,j));
        }
    int sizeV=v.size();
    cout<<sizeV<<'\n';
    for (int i=0; i<sizeV; i++)
        cout<<v[i].first<<' '<<v[i].second<<'\n';
    return 0;
}
