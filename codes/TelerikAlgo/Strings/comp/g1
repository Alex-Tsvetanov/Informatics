#include <iostream>
#include <string>

using namespace std;

using ANSWER = long long;

ANSWER max(ANSWER a, ANSWER b)
{   return (a > b)? a : b; }

string X, Y;
//short LCSuff [2896][2896];
ANSWER LCSuff [2][1<<14];

ANSWER LCSubStr(short m, short n)
{
    ANSWER result = 0;

    for (short i=0; i<=m; i++)
    {
        for (short j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i%2][j] = 0;
            else if (X[i-1] == Y[j-1])
            {
                LCSuff[i%2][j] = LCSuff[(i-1)%2][j-1] + 1;
                result = max(result, LCSuff[i%2][j]);
            }
            else LCSuff[i%2][j] = 0;
        }
    }
    return result;
}

int main()
{
    cin.tie (nullptr);
    ios::sync_with_stdio (false);
    getline (cin, X);
    //cout << X << endl;
    getline (cin, Y);

    ANSWER optimum = LCSubStr(X.size (), Y.size ());
    cout << optimum << "\n";
}
