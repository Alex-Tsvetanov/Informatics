#include<iostream>
#include<list>
using namespace std;
bool Check(int start, int finish, list<int> L[], int n)
{
    if(start==finish) return true;
    else
    {
        int k = L[start].size();
        while(!L[start].empty())
        {
            int t = L[start].front();
            L[start].pop_front();
            if(Check(t,finish,L,n)) return true;
        }
        return false;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    list<int> CanSendTo[n];
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        CanSendTo[x].push_back(y);
    }
    list<int> Result;
    for(int i=0; i<n; i++)
    {
        bool b = true;

        for(int k=0; k<n; k++)
        {
            list<int> Test[n];
            for(int j=0; j<n; j++) Test[j]=CanSendTo[j];
            bool c = Check(i, k, Test, n);
            if(!c) b = false;
        }
        if(b) Result.push_back(i);
    }
    cout<<Result.size()<<endl;
    if(!Result.empty())
    {
        cout<<Result.front();
        Result.pop_front();
    }
    while(!Result.empty())
    {
        cout<<" "<<Result.front();
        Result.pop_front();
    }
    cout<<endl;
    return 0;
}
