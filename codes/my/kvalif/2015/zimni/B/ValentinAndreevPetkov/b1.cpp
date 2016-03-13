#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

short nTable[1000][1000];

int sum(int *pBegin, int nCount, int iBegin)
{
    int nTotal = 0;

    for (short i = iBegin; i < nCount + iBegin; i++)
        nTotal += *(pBegin + i);

    return nTotal;
}

int biggest(int *pBegin, int nSize, int nCount)
{
    int nBigSum = -1000000000;

    for (short i = 0; i <= (nCount - nSize); i++)
        if (nBigSum < sum(pBegin, nSize, i))
            nBigSum = sum(pBegin, nSize, i);

    return nBigSum;
}

int main()
{
    int nTotalRows, nTotalCols, nTargetRows, nTargetCols;
    cin >> nTotalRows >> nTotalCols >> nTargetRows >> nTargetCols;

    for (short i = 0; i < nTotalRows; i++)
        for (short j = 0; j < nTotalCols; j++)
            cin >> nTable[i][j];

    int nTotals[max(nTargetCols,nTargetRows)];

    int nBig = -1000000000, nBiggest = -1000000000;

    if (nTargetCols > nTargetRows)
        for (short s = 0; s <= nTotalCols - nTargetCols; s++)
        {
            for (short i = 0; i < nTotalRows; i++)
            {
                int nTotal = 0;

                for (short j = 0; j < nTargetCols; j++)
                    nTotal += nTable[i][j+s];

                nTotals[i] = nTotal;
            }

            nBig = biggest(nTotals, min(nTargetCols,nTargetRows), nTotalRows);

            if (nBig > nBiggest)
                nBiggest = nBig;
        }

    else
        for (short s = 0; s <= nTotalRows - nTargetRows; s++)
        {
            for (short i = 0; i < nTotalCols; i++)
            {
                int nTotal = 0;

                for (short j = 0; j < nTargetRows; j++)
                    nTotal += nTable[j+s][i];

                nTotals[i] = nTotal;
            }

            nBig = biggest(nTotals, min(nTargetCols,nTargetRows), nTotalCols);

            if (nBig > nBiggest)
                nBiggest = nBig;
        }

    cout << nBiggest << endl;

    system("pause");

    return 0;
}
