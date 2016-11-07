#include <iostream>
#include<string>
#include<vector>
using namespace std;
string s,a;
vector<int>ans;
int main()
{
    int i,br,sz;
    cin>>s;
    while(1)
    {
        br=0;
        cin>>a;
        if(a[0]=='2')break;
        sz=a.size();
        for(i=0;i<sz;i++)
        {
            br+=a[i];
        }
        if(br%2==0)ans.push_back(0);
        else ans.push_back(1);
    }
    sz=ans.size();
    for(i=0;i<sz;i++)
        cout<<ans[i];
    cout<<endl;
    return 0;
}
