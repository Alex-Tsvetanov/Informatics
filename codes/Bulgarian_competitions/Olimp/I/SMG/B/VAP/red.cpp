#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    short nCount;
    cin >> nCount;

    vector<int> vecNumbers, vecNumbersSort;

    for (short i = 0; i < nCount; i++)
    {
        int ciin;
        cin >> ciin;

        vecNumbers.push_back(ciin);
        vecNumbersSort.push_back(ciin);

    }

    sort(vecNumbersSort.begin(), vecNumbersSort.end());

    short index_begin_small, index_begin_big, index_end_small, index_end_big;

    for (short i = 0; i < nCount; i++)
        if (vecNumbers[i] == vecNumbersSort[0])
        {
            index_begin_small = i + 1;
            break;
        }

    for (short i = 0; i < nCount; i++)
        if (vecNumbers[i] == vecNumbersSort[nCount - 1])
        {
            index_begin_big = i + 1;
            break;
        }

    for (short i = nCount - 1; i >= 0; i--)
        if (vecNumbers[i] == vecNumbersSort[0])
        {
            index_end_small = i + 1;
            break;
        }

    for (short i = nCount - 1; i >= 0; i--)
        if (vecNumbers[i] == vecNumbersSort[nCount - 1])
        {
            index_end_big = i + 1;
            break;
        }

    if (abs(index_begin_small - index_end_big) >= abs(index_begin_big - index_end_small))
        cout << index_begin_small << " " << index_end_big << endl;
    else
        cout << index_begin_big << " " << index_end_small << endl;

    return 0;
}
