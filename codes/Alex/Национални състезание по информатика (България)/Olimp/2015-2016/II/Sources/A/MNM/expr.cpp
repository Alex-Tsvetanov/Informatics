#include <map>
#include <vector>
#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
string s;
map<char, int> val;
vector<char> ch;
char lt[26];
bool vl[1008];
int dep[1008];
int maxD = 0;

void solve()
{
    int open = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
        {
            open++;
            dep[i] = -1;
            maxD = max(maxD, open);
            continue;
        }
        if(s[i] == ')')
        {
            open--;
            dep[i] = -2;
            continue;
        }
        dep[i] = open;
    }
}

void eval()
{
    vector<bool> vals;
    vector<int> dpths;
    bool val = vl[0];
    for(int i = 1; i < n; i++)
    {
        if(dep[i] == -1 or dep[i] == -2)
        {
            vals.push_back(val);
            val = vl[s[i+1] - 'a'];
            dpths.push_back(dep[i-1]);
            i += 2;
        }
        if(i < n)
        {val &= vl[s[i] - 'a']; val = !val;}
    }
    vals.push_back(val);
    dpths.push_back(dep[n-1]);

    int mxd=dpths[0], ind = 0;

    for(int i = 1; i < dpths.size(); i++)
    {
        if(mxd < dpths[i])
        {
            mxd = dpths[i];
            ind = i;
        }
    }

    val = vals[ind];
    int dpVal = dpths[ind];
    int i = ind + 1;
    int j = ind - 1;
    while(true)
    {
        if(i >= dpths.size() and j<0) break;
        if(j >= 0) if(dpths[j] == dpVal - 1) val &= vals[j], val = !val, j--;
        if(i < dpths.size()) if(dpths[i] == dpVal - 1) val &= vals[i], val = !val, i++;
        dpVal--;
    }
    cout << val << endl;
}

int main()
{
    cin >> s;
    n = s.size();

    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(' and s[i + 2] == ')')
        {
            s.erase(s.begin() + i);
            s.erase(s.begin() + i + 1);
            n = s.size();
        }
    }

    int open = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] != '(' and s[i] != ')' and lt[s[i] - 'a'] == 0) ch.push_back(s[i]), lt[s[i] - 'a'] = 1;
    }
    sort(ch.begin(), ch.end());

    char letter = 'a';
    for(int i = 0; i < ch.size(); i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(s[j] == ch[i]) s[j] = letter;
        }
        letter = char(letter + 1);
    }
    solve();
    string ggg;
    do
    {
        cin >> ggg;
        for(int i = 0; i < ch.size(); i++) vl[i] = ggg[i] - '0';
        eval();
    }while(ggg.size() > 1);
}
