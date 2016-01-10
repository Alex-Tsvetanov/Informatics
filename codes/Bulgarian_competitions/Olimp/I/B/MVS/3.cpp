#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
long ans = 0;

vector<int> Encode(int a)
{
    vector<bool> code;
    while(a>0)
    {
        code.push_back(a%2);
        a/=2;
    }
    vector<int> ans;
    for(int i = 0; i<code.size(); i++)
    {
        if(code[i])
            ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool doubleAdd(vector<int> a)
{
    int first = -1;
    for(int i = 0; i<a.size(); i++)
    {
        if(a[i]>0 && first == -1)
            first = a[i];
        if(a[i]>0 && a[i]<first)
            return true;
        if(a[i] == 0)
            return false;
    }
}

void addAt(vector<int> &a, int index, int value)
{
    a.push_back(a[a.size()-1]);
    int i = a.size()-2;
    while(i>index)
    {
        a[i] = a[i-1];
        i--;
    }
    a[index] = value;
}

bool toStop(vector<int> a)
{
    for(int i = 0; i<a.size(); i++)
    {
        if(a[i]>0)
            return false;
    }
    return true;
}

void decompose(vector<int> &a)
{
    for(int i = a.size()-1; i>=0; i--)
    {
        if(a[i]>0)
        {
            a[i]--;
            addAt(a, i+1, a[i]);
            return;
        }
    }
}

void solve(vector<int> &a)
{
    ans++;
    if(doubleAdd(a))
    {
        ans++;
    }
    if(toStop(a))
        return;
    decompose(a);
    solve(a);

}

int main()
{
    cin>>n;
    vector<int> N = Encode(n);
    solve(N);
    cout<<ans;
    return 0;
}
