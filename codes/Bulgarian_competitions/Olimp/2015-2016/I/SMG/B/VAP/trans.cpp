#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int nCountCities;
    cin >> nCountCities;

    int nCountRoads;
    cin >> nCountRoads;

    int nRoadsPerCity[nCountCities];

    for (int i = 0; i < nCountCities; i++)
        nRoadsPerCity[i] = 0;

    for (int i = 0; i < nCountRoads; i++)
    {
        int first, second;
        cin >> first >> second;

        nRoadsPerCity[first - 1]++;
        nRoadsPerCity[second - 1]++;
    }

    int nTransGoal;
    cin >> nTransGoal;

    int nCountTrans = 0;

    for (int i = 0; i < nCountCities; i++)
        if (nRoadsPerCity[i] >= nTransGoal)
            nCountTrans++;

    if (nCountTrans == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    else
    {
        cout << nCountTrans << endl;

        for (int i = 0; i < nCountCities; i++)
            if (nRoadsPerCity[i] >= nTransGoal)
                cout << i + 1 << " ";
    }

    return 0;
}
