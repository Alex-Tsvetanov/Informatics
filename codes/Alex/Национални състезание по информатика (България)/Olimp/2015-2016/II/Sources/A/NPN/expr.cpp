#include <iostream>

using namespace std;

struct Interval
{
    int from, to;
}arr[1000001];

string s, current;
int n, A[1000001], br, num, b, k, B[1000001], d[1000001], p[1000001], brans;
bool used[1000001];
int output[1000001];

int main()
{
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++)
        if (s[i] == '(') A[br++] = i;
    for (int i = br - 1; i>= 0; i--)
    {
        for (int j = A[i] + 1; j < n; j++)
            if (s[j] == ')' and !used[j])
            {
                arr[num].from = A[i];
                arr[num].to = j;
                p[A[i]] = j;
                num++;
                used[j] = 1;
                break;
            }
    }
    while (cin >> current)
    {
        if (current == "2") break;
        else
        {
            for (int i = 0; i < current.size(); i++)
                if (current[i] == '0') B[i] = 0; else B[i] = 1;

            for (int i = 0; i < num; i++)
            {
                if (i == 0)
                {
                    k = B[s[arr[i].from + 1] - 'a'];
                    for (int j = arr[i].from + 2; j < arr[i].to; j++)
                    {
                        k &= B[s[j] - 'a'];
                        k = !k;
                    }
                    d[i] = k;
                }
                else
                {
                    k = B[s[arr[i].from + 1] - 'a'];
                    for (int j = arr[i].from + 2; j < arr[i].to; j++)
                    {
                        if (s[j] != '(' and s[j] != ')')
                        {
                            k &= B[s[j] - 'a'];
                            k = !k;
                        }
                        else
                        {
                            k &= d[i - 1];
                            k = !k;
                            j = p[j];
                        }
                    }
                    d[i] = k;
                }
            }
            int h = num - 1;
            int ans;
            if (s[0] != '(')
            {
                ans = B[s[0] - 'a'];
                for (int i = 1; i < n; i++)
                {
                    if (s[i] != '(' and s[i] != ')')
                    {
                        ans &= B[s[i] - 'a'];
                        ans = !ans;
                    }
                    else
                    {
                        ans &= d[h];
                        ans = !ans;
                        i = p[arr[h].from];
                        h--;
                    }
                }
            }
            else
            {
                ans = d[h];
                int i = p[arr[h].from] + 1;
                h--;
                for (i; i < n; i++)
                {
                    if (s[i] != '(' and s[i] != ')')
                    {
                        ans &= B[s[i] - 'a'];
                        ans = !ans;
                    }
                    else
                    {
                        ans &= d[h];
                        ans = !ans;
                        i = p[arr[h].from];
                        h--;
                    }
                }
            }
            output[brans++] = ans;
        }
    }
    for (int i = 0; i < brans; i++)
        cout << output[i];
    cout << endl;
}
/*
a(a)(ab(ca)bb)c
011
100
010
111
001
2

(aaaaaaa)
1
0
2

(aaa)(aaa)
1
2
*/
