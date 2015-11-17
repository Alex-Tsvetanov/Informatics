#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vecShapes[10000];

    short nTotalShapes = 0;

    for (short nNumber = 0;true; nNumber++)
    {
        short nCoordCount = 0;
        cin >> nCoordCount;

        if (nCoordCount == 0)
            break;

        nTotalShapes++;

        for (short i = 0; i < nCoordCount*2; i++)
        {
            int nCurrent = 0;
            cin >> nCurrent;

            vecShapes[nNumber].push_back(nCurrent);
        }
    }

    int nShapes[10000][2];

    for (int nShape = 0; nShape < nTotalShapes; nShape++)
    {
        int nMAX_X = vecShapes[nShape][0], nMAX_Y = vecShapes[nShape][1], nMin_X = vecShapes[nShape][0], nMin_Y = vecShapes[nShape][1];

        for (int i = 2; i < vecShapes[nShape].size(); i += 2)
        {
            if (nMAX_X < vecShapes[nShape][i])
                nMAX_X = vecShapes[nShape][i];

            if (nMAX_Y < vecShapes[nShape][i + 1])
                nMAX_Y = vecShapes[nShape][i + 1];

            if (nMin_X > vecShapes[nShape][i])
                nMin_X = vecShapes[nShape][i];

            if (nMin_Y > vecShapes[nShape][i + 1])
                nMin_Y = vecShapes[nShape][i + 1];
        }

        nShapes[nShape][0] = abs(nMAX_X - nMin_X)*abs(nMAX_Y - nMin_Y);
        nShapes[nShape][1] = vecShapes[nShape].size()/2;
    }

    int nMinSize = 1;

    for (int nShape = 1; nShape < nTotalShapes; nShape++)
    {
        if (nShapes[nShape][0] < nShapes[0][0])
        {
            swap(nShapes[nShape][0], nShapes[0][0]);
            swap(nShapes[nShape][1], nShapes[0][1]);

            nMinSize = nShape + 1;
        }

        if (nShapes[nShape][0] == nShapes[0][0] && nShapes[nShape][1] < nShapes[0][1])
        {
            swap(nShapes[nShape][1], nShapes[0][1]);

            nMinSize = nShape + 1;
        }
    }

    cout << nMinSize << endl;

    return 0;
}
