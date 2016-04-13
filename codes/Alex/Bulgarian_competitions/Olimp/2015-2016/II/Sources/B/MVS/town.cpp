#include<stack>
#include<vector>
#include<iostream>
#include<string>
#include<sstream>
#include<windows.h>
using namespace std;

vector < vector < long > > town(200001);
vector < vector < long > > town1(200001);
long n, a, b;

void fillPriorityStack(long curr, stack<long> &toFill, vector<bool>used)
{
    for(long i = 0; i<town1[curr].size(); i++)
    {
        if(!used[town1[curr][i]])
            toFill.push(town1[curr][i]);
    }
    for(long i = 0; i<town[curr].size(); i++)
    {
        if(!used[town[curr][i]])
            toFill.push(town[curr][i]);
    }
    return;
}

bool exsist(long a, vector<long> b)
{
    for(int i = 0; i<b.size(); i++)
        if(b[i]==a)
            return 1;
    return 0;
}

bool dfs(long a, long b, long &ans)
{
    long currAns = 0;
    ans = 0;
    bool ret = 0;
    stack<long>next;
    next.push(a);
    vector<bool>used(200001);
    fill(used.begin(), used.end(), 0);
    long top, old, old1;
    do
    {
        old = top;
        bool bBreak = 0;
        bool bFill = 1;
        top = next.top();
        if(exsist(top, town1[old]))
            currAns++;
        while(used[top])
        {
            next.pop();
            old1 = top;
            if(next.empty())
            {
                bBreak = 1;
                break;
            }
            top = next.top();
        }
        if(bBreak)
            break;
        used[top] = 1;
        cout<<top<<" "<<old<<endl;;
        if(top == b)
        {
            cout<<"cANS= "<<currAns<<endl;
            ret = 1;
            if(currAns!=0&&ans==0)
                ans = currAns;
            if(currAns<ans)
                ans = currAns;
            currAns = 0;
            used[top] = 0;
            next.pop();
            top = next.top();
            bFill = 0;
        }
        if(bFill)
            fillPriorityStack(top, next, used);
    }while(!next.empty());
    return ret;
}

int main()
{
    cin>>n>>a>>b;
    string dummy;
    getline(cin, dummy);
    while(1)
    {
        long p, q;
        string s;
        getline(cin, s);
        if(s[0]<'0' || s[0]>'9')
            break;
        istringstream ss(s);
        ss>>p;ss>>q;
        town[p].push_back(q);
        town1[q].push_back(p);
    }
    long ans=0;
    if(dfs(a, b, ans))
    {
        cout<<ans;
    }
    else
        cout<<"X";
    return 0;
}
