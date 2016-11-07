#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

string s;
int N;
vector <int> all[10009];

/*void createPalindr()
{
    for (int i = 0; i < N; ++i)
    {
        all[i].push_back(i+1);
        //cout<<i+1<<" "<<i+1<<endl;
        if (i < N - 1 and s[i] == s[i + 1])
        {

            int from = i, to = i + 1;
            //cout<<i+1<<" "<<i+2<<endl;
            all[i].push_back(i+2);
            for (int j = 1; from - j >= 0 and to + j < N; ++j)
                if (s[from-j] == s[to+j]) all[from-j].push_back(to+j+1);
                    //cout<<from-j+1<<" "<<to+j+1<<endl;
                else break;
        }
        for (int j = 1; i - j >= 0 and i + j < N; ++j)
            if (s[i-j] == s[i+j]) all[i-j].push_back(i+j+1);
                //cout<<i-j+1<<" "<<i+j+1<<endl;
            else break;
            //cout<<"*";
    }
}*/

void createPalindr()
{
    for (int i = 0; i < N; ++i)
    {
        all[i].push_back(i+1);
        if (i < N - 1 and s[i] == s[i + 1])
        {
            int from = i, to = i + 1;
            all[i].push_back(i+2);
            for (int j = 1; from - j >= 0 and to + j < N; ++j)
                if (s[from - j] == s[to + j]) all[from - j].push_back(to + j + 1);
                else break;
        }
        for (int j = 1; i - j >= 0 and i + j < N; ++j)
            if (s[i - j] == s[i + j]) all[i - j].push_back(i + j + 1);
            else break;
    }
}

bool u[10009];
int l,d;

int bfs(int from)
{
    queue <int> q;
    q.push(from);
    u[from] = true;
    while (!q.empty())
    {
        l = q.size();
        while (l--)
        {
            from = q.front();
            q.pop();
            for (int i = 0; i < all[from].size(); ++i)
                if (!u[all[from][i]])
            {
                q.push(all[from][i]);
                u[all[from][i]] = true;
                if (all[from][i] == N) return d;
            }
        }
        d++;
    }
}

int main()
{
    cin>>s;
    N = s.size();
    createPalindr();
    cout<<bfs(0)<<endl;
}
