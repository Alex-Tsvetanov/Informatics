#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int total = 0;
    int numberOfTargets, numberOfSpotsHits, numberOfStrengths;
    int targets[10000][3], markedSpots[10][2];

    cin >> numberOfTargets;
    cin >> numberOfSpotsHits;
    cin >> numberOfStrengths;
    for (int i=0; i<numberOfTargets; i++)
    {
        cin >> targets[i][0];
        cin >> targets[i][1];
        cin >> targets[i][2];
    }
    for (int i=0; i<numberOfSpotsHits; i++)
    {
        cin >> markedSpots[i][0];
        cin >> markedSpots[i][1];
    }

    int lastPointsWon = -1;

    for (int i=0; i<numberOfStrengths; i++)
    {
        int power;
        cin >> power;
        int pointsToGive = 0;
        for (int j=0; j<numberOfSpotsHits; j++)
        {
            for (int k=0; k<numberOfTargets; k++)
            {
                if (lastPointsWon%2==0)
                    power*=2;

                double temp = sqrt(pow(targets[k][0] - markedSpots[j][0], 2) + pow(targets[k][1] - markedSpots[j][1], 2)) + targets[k][2];
                if (temp < power)
                    pointsToGive++;

                if (lastPointsWon%2==0)
                    power/=2;
            }
        }
        total += pointsToGive;
        lastPointsWon = pointsToGive;
    }

    cout << total << endl;

    return 0;
}
