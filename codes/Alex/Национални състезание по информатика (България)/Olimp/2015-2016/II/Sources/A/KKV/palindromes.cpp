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
 
long long int minPal(string  str)
{
    long long int n = str.length();
    long long int C[n][n];
    bool P[n][n];
    long long int i, j, k, L;
    for (i = 0; i < n; i++)
    {
        P[i][i] = true;
        C[i][i] = 0;
    }
    for (L = 2; L <= n; L++)
    {
        for (i = 0; i < n - L + 1; i++)
        {
            j = i + L - 1;
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
            if (P[i][j] == true)
                C[i][j] = 0;
            else
            {
                C[i][j] = LLONG_MAX;
                for (k = i; k <= j - 1; k++)
                    C[i][j] = min (C[i][j], C[i][k] + C[k + 1][j] + 1);
            }
       
     }
    }return C[0][n-1];
}
 
int main()
{
    string str;
    cin >> str;
    cout<< minPal(str) <<endl;
    return 0;
}
