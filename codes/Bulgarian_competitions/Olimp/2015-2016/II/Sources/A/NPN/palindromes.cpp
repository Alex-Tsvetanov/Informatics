#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int n, l, r, k = 999999;
string s;
vector <int> List[10010];

void findResult(int pos, int current)
{
    if (pos == n)
    {
        k = min(k, current);
        return;
    }
    else
    {
        if (List[pos].size() == 0) findResult(pos + 1, current + 1);
        else
        {
            for (int i = 0; i < List[pos].size(); i++)
                findResult(List[pos][i] + 1, current + 1);
        }
    }
}

int main()
{
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i + 1])
        {
            l = i, r = i + 1;
            List[l].push_back(r);
            int l1 = l, r1 = r;
            while (s[l - 1] == s[r + 1] and l - 1 >= 0 and r + 1 < n)
            {
                l--, r++;
                if (s[l] == s[r]) List[l].push_back(r);
            }
            if (s[l] != s[r] or l < 0 or r >= n) l++, r--;
            if (l1 != l or r1 != r) List[l].push_back(r);

        }
        l = i, r = i;
        while (s[l - 1] == s[r + 1] and l - 1 >= 0 and r + 1 < n)
        {
            l--, r++;
            if (s[l] == s[r]) List[l].push_back(r);
        }
        if (s[l] != s[r] or l < 0 or r >= n) l++, r--;
        if (l != r) List[l].push_back(r);

    }
    findResult(0, 0);
    cout << k - 1 << endl;
}
/*
babababbabbbbabababaaab
abbabab
*/
