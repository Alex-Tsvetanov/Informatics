#include <iostream>
#include <algorithm>
using namespace std;

short nAppleField[1000][1000];

void next_day(int nDay, int nX, int nY)
{
    for (short i = 0; i < nX; i++)
        for (short j = 0; j < nY; j++)
            if (nAppleField[i][j] == nDay)
            {
                if (i > 0 && nAppleField[i-1][j] == 0)
                nAppleField[i-1][j] = nDay + 1;
                if (j > 0 && nAppleField[i][j-1] == 0)
                nAppleField[i][j-1] = nDay + 1;
                if (i < nX && nAppleField[i+1][j] == 0)
                nAppleField[i+1][j] = nDay + 1;
                if (j < nY && nAppleField[i][j+1] == 0)
                nAppleField[i][j+1] = nDay + 1;
            }
}

int main()
{
    int nTotalRows, nTotalCols, nDays;
    cin >> nTotalRows >> nTotalCols >> nDays;

    int nX_1, nX_2, nY_1, nY_2;
    cin >> nX_1 >> nY_1 >> nX_2 >> nY_2;

    for (short i = 0; i < nTotalCols; i++)
        for (short j = 0; j < nTotalRows; j++)
            nAppleField[i][j] = 0;

    nAppleField[nY_1-1][nX_1-1] = 1;
    nAppleField[nY_2-1][nX_2-1] = 1;

    for (short i = 0; i < nDays; i++)
    {
        next_day(i + 1, nTotalRows+1, nTotalCols+1);

    }


    int nTotal = 0;

    for (short i = 0; i < nTotalCols; i++)
        for (short j = 0; j < nTotalRows; j++)
            if (nAppleField[i][j] == 0)
                nTotal++;

    cout << nTotal << endl;

    return 0;
}
