#include <iostream>
#include <set>
#define MAXN 10001
using namespace std;
set<int> lens[MAXN];
int ans;
string s;
void evensFrom(int x)
{
    for (int i = 0; x - i >= 0 && i + x + 1 < s.size(); i++)
        if (s[x-i] == s[x+i+1])
            lens[x-i].insert((i+1)*2);
        else
            break;
}
void oddsFrom(int x)
{
    for (int i = 0; x - i >= 0 && i + x < s.size(); i++)
        if (s[x-i] == s[x+i])
            lens[x-i].insert(i*2+1);
        else
            break;
}
void rec(int pos, int moves)
{
    if (ans <= moves)
        return;
    set<int>::iterator it = lens[pos].end();
    it--;
    if (*it + pos == s.size())
    {
        ans = moves;
        return;
    }
    for (; ; it--)
    {
        rec(pos+*it, moves+1);
        if (it == lens[pos].begin())
            break;
    }
}
int main ()
{
    ans = 2147483647;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        evensFrom(i);
    for (int i = 0; i < s.size(); i++)
        oddsFrom(i);
    rec(0, 0);
    cout << ans << endl;
    return 0;
}
