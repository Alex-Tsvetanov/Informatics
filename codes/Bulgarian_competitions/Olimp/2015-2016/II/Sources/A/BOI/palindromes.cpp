#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>
using namespace std;
 
long long int min (long long int a, long long int b)
{
    return (a < b)? a : b;
}
 
long long int m(string  str)
{
    long long int n = str.length();
    long long int c[n][n];
    bool p[n][n];
    long long int i, j, k, L;
    for (i = 0; i < n; i++)
    {
        p[i][i] = true;
        c[i][i] = 0;
    }
    for (L = 2; L <= n; L++)
    {
        for (i = 0; i < n - L + 1; i++)
        {
            j = i + L - 1;
            if (L == 2)
                p[i][j] = (str[i] == str[j]);
            else
                p[i][j] = (str[i] == str[j]) && p[i + 1][j - 1];
            if (p[i][j] == true)
                c[i][j] = 0;
            else
            {
                c[i][j] = LLONG_MAX;
                for (k = i; k <= j - 1; k++)
                    c[i][j] = min (c[i][j], c[i][k] + c[k + 1][j] + 1);
            }
       
     }
    }return c[0][n-1];
}
 
int main()
{
    string str;
    cin >> str;
    cout<< m(str) <<endl;
    return 0;
}
