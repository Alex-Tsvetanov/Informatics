#include<iostream>
#include<vector>

using namespace std;

vector<int> ccout;

void solve()
{
    int n;cin>>n;
    vector<int> a;
    vector<int> b;
    for(int i=0, local;i<n;i++)
    {
        cin>>local;
        a.push_back(local);
    }
    cin>>n;
    for(int i=0, local;i<n;i++)
    {
        cin>>local;
        b.push_back(local);
    }
    if(a.size()>b.size())swap(a,b);
    vector<int> c;

    for(int i=0;i<a.size();i++)
    {
        for(int j=0;j<b.size();j++)
        {
            if(a[i]==b[j])
            {
                c.push_back(j);
                break;
            }
        }
    }

    for(int i=1;i<c.size();i++)
    {
        if(c[i]<c[i-1])
        {
            ccout.push_back(0);
            return;
        }
    }
    ccout.push_back(1);
}

int main(){
    for(int i=0;i<5;i++)
    {
        solve();
    }
    for(int i=0;i<5;i++)
    {
        cout<<ccout[i];
    }
    cout<<endl;

    return 0;
}
