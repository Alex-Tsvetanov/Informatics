#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> encode;
int decode[10010];
int num[10010];
vector<int> ans;
int main(){
        cin.tie(NULL);
        ios::sync_with_stdio(false);
        int p,m;
        cin>>p>>m;
        int br=1,a,b;
        for(int i=0;i<m;i++)
        {
                cin>>a>>b;
                if(encode[a]==0)
                {
                        encode[a]=br;
                        decode[br]=a;
                        br++;
                }
                a=encode[a];
                if(encode[b]==0)
                {
                        encode[b]=br;
                        decode[br]=b;
                        br++;
                }
                b=encode[b];
                num[a]++;
                num[b]++;
        }
        int k;
        cin>>k;
        for(int i=1;i<br;i++)
        {
                if(num[i]>=k)
                {
                        ans.push_back(decode[i]);
                }
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<"\n";
        for(int i=0;i<ans.size();i++)
        {
                if(i!=0)
                {
                        cout<<" ";
                }
                cout<<ans[i];
        }
        if(ans.size()!=0)
        {
                cout<<"\n";
        }
        return 0;
}