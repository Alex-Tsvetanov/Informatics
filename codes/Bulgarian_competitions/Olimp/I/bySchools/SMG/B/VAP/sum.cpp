#include <iostream>

using namespace std;


//short const nNumbers[] = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
long long nTotalWays = 1;
/*
void calc(short nTotal)
{
    for (short a1 = nTotal; a1 >= 0; a1 -= 2048)
    for (short a2 = a1; a2 >= 0; a2 -= 1024)
    for (short a3 = a2; a3 >= 0; a3 -= 512)
    for (short a4 = a3; a4 >= 0; a4 -= 256)
    for (short a5= a4; a5 >= 0; a5 -= 128)
    for (short a6 = a5; a6 >= 0; a6 -= 64)
    for (short a7 = a6; a7 >= 0; a7 -= 32)
    for (short a8 = a7; a8 >= 0; a8 -= 16)
    for (short a9 = a8; a9 >= 0; a9 -= 8)
    for (short a10 = a9; a10 >= 0; a10 -= 4)
    for (short a11 = a10; a11 >= 0; a11 -= 2)
    for (short a12 = 0; a12 >= 0; a12 -= 1)
        if (a12 == 0)
            nTotalWays++;
}
*/

int main ()
{
    long long nSums[3002];

    nSums[0] = 1;
    nSums[1] = 2;
    nSums[2] = 2;
    nSums[3] = 4;
    nSums[4] = 4;
    nSums[5] = 6;
    nSums[6] = 6;
    nSums[7] = 10;
    nSums[8] = 10;
    nSums[9] = 14;
    nSums[10] = 14;

    for (short i = 10; i < 3002; i += 2)
    {
        nTotalWays = nSums[i-2] + nSums[(i-2)/2];
        //calc(i);
        nSums[i - 1] = nTotalWays;
        nSums[i] = nTotalWays;
    }

    short nIndex;
    cin >> nIndex;

    cout << nSums[nIndex - 1];

    return 0;
}
