#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> a[10];
long long n, f=1;

int calcLog(long long x)
{
    long long br=0, deg=1, y=x;
    while (x!=0)
    {
        x/=2;
        deg*=2;
        br++;
    }
    if (deg/2==y)
    {
        br--;
        f=0;
    }
    return br;
}

string binExp(int x, int l)
{
    string ans="";
    while (x!=0)
    {
        ans=ans+(char)((x%2)+'0');
        x/=2;
    }
    while (ans.size()<l) ans=ans+'0';
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n;
    if (n>500)
    {
        cout<<calcLog(n)<<endl;
        return 0;
    }
    int cnt=calcLog(n);
    for (int i=1; i<n+f; i++)
    {
        string s=binExp(i, cnt);
        for (int j=0; j<s.size(); j++)
        {
            if (s[j]=='1') a[j].push_back(i);
        }
    }

    cout<<cnt<<endl;
    for (int i=0; i<cnt; i++)
    {
        cout<<a[i].size();
        for (int j=0; j<a[i].size(); j++)
        {
            cout<<' '<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}
