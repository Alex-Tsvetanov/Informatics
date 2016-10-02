#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct stru
{
    int a, b, c;
};

vector<int> vuzmojni;
vector<set<int>> deca;
queue<stru> Q;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    deca.resize(10);
    for(int i = 0; i < 3; i++)
    {
        int x;
        cin>>x;
        for(int i = 1; i*x<100; i++)
        {
            int chislo = i*x;
            int b = chislo%10;
            chislo/=10;
            int a = chislo%10;
            deca[a].insert(b);
        }
    }
    int res = 0;
    for(int i = 1; i<=9; i++)
    {
        Q.push({i, i, 1});
        while(!Q.empty())
        {
            auto sq = Q.front();
            Q.pop();
            if(sq.c!=n)
            {
                for(auto &x:deca[sq.a])
                {
                    if(x!=sq.a)
                    {
                        Q.push({x, sq.a, sq.c+1});
                    }
                }
            }
            else
            {
                res++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}
