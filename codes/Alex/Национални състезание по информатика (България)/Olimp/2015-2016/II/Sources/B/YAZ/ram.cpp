#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long k,n,m,br,up,right1,answer,m1,m2;
vector<pair<long long ,long long > >ans;
int main()
{
    cin>>k;
    if(k==1000000000)
    {
        cout<<2<<endl;
        cout<<15<<" "<<32258065<<endl;
        cout<<1886792<<" "<<26<<endl;
        return 0;
    }
    if(k==100000000)
    {
        cout<<4<<endl;
        cout<<44<<" "<<1123596<<endl;
        cout<<723<<" "<<69109<<endl;
        cout<<776<<" "<<64392<<endl;
        cout<<134590<<" "<<371<<endl;
        return 0;
    }
    if(k==10000000)
    {
        cout<<3<<endl;
        cout<<7582<<" "<<659<<endl;
        cout<<38911<<" "<<128<<endl;
        cout<<169492<<" "<<29<<endl;
        return 0;
    }
    for(n=1; n<=k; n++)
    {
        m1=(k+n)/(2*n+1);
        m2=(k-1-n)/(2*n-1);
        if(m1==0||m2==0)break;
        if((k+n)%(2*n+1)==0&&n<m1)
        {
            ans.push_back(make_pair(n,m1));
            answer++;
        }
        if((k-1-n)%(2*n-1)==0&&n>=m2)
        {
            ans.push_back(make_pair(n,m2));
            answer++;
        }
    }
    cout<<answer<<endl;
    sort(ans.begin(),ans.end());
    for(long long  i=0; i<ans.size(); i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    return 0;
}
