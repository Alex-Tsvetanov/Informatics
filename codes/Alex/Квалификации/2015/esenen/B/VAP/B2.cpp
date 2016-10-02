#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<short> nCountCollect;
vector<int> nJumps;

int nCollectedMax = 0;
int nJumpsMin = 0;

void solve_dis(int nCurrentPos, int nCurrentMax)
{
    for (short i = 0; i < nJumps.size(); i++)
    {
        if (nCurrentPos + nJumps[i] > nCountCollect.size() - 1)
            return;

        nCurrentMax += nCountCollect[nCurrentPos + nJumps[i]];
        nCurrentPos += nJumps[i];

        if (nCurrentMax > nCollectedMax)
            nCollectedMax = nCurrentMax;

        if (nCurrentPos > nJumpsMin && nCountCollect[nCurrentPos] != 0)
            nJumpsMin = nCurrentPos;

        solve_dis(nCurrentPos, nCurrentMax);
    }
}

int main()
{
    int nCount = 0;
    cin >> nCount;

    int nCountJumps = 0;
    cin >> nCountJumps;

    for (; nCountJumps > 0; nCountJumps--)
    {
        int nCurrent = 0;
        cin >> nCurrent;

        nJumps.push_back(nCurrent);
    }

    for (; nCount >= 0; nCount--)
    {
        short nCurrent = 0;
        cin >> nCurrent;

        nCountCollect.push_back(nCurrent);
    }

    sort(nJumps.begin(), nJumps.end());

    solve_dis(0,nCountCollect[0]);

    cout << nCollectedMax << " " << nJumpsMin << endl;

    return 0;
}
