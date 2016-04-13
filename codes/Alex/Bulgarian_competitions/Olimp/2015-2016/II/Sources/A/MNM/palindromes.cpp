#include <set>
#include <queue>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

const int MAX_N = 10008;

int n;
string s;
vector<int> graph[MAX_N];

void getPals(int i)
{
    int p = i;
    int j = i;
    while(true)
    {
        if(i == 0 and j == n - 1) break;

        if(s[i-1] == s[j+1])
        {
            i--, j++;
            graph[i].push_back(j + 1);
        }
        else break;
    }

    i = p;
    j = i;
    graph[i].push_back(i + 1);
    if(i + 1 <= n - 1) if(s[i + 1] == s[i]) j = i + 1, graph[i].push_back(j + 1);
    while(true)
    {
        if(i == 0 and j == n - 1) break;

        if(s[i-1] == s[j+1])
        {
            i--, j++;
            graph[i].push_back(j + 1);
        }
        else break;
    }
}

bool usedd[MAX_N];

int bfs()
{
    queue<int> q;
    q.push(0);
    usedd[0] = true;
    int dep = 0;
    while(q.empty() == false)
    {
        int sz = q.size();
        while(sz--)
        {
            int node = q.front();
            q.pop();
            for(int i = 0; i < graph[node].size(); i++)
                if(usedd[graph[node][i]] == false)
                {
                    usedd[graph[node][i]] = true;
                    q.push(graph[node][i]);
                    if(graph[node][i] == n) return dep;
                }
        }
        dep++;
    }
}

int main()
{
    cin >> s;
    n = s.size();

    for(int i = 0; i < n; i++)
    {
        getPals(i);
    }

    cout << bfs() << endl;
}
/*
abba
abbabab
abbc
bananna
abcxxxy
abbabbaxxxyxx
aaabaaa
aa
aaa
aaaa
*/
