#include <iostream>
using namespace std;
int main ()
{
    long long M, N, S, broi = 0, ost;
    cin >> M >> N;
    S = M * N;
    while (S > 1)
    {
        S = S / 2;
        broi++;
        ost = S % 2;
        if (ost == 1)
        {
            broi++;
        }
    }
    if (M == 1 or N == 1)
    {
        cout << broi << endl;
    }
    if (M > 1 and N > 1)
    {
        cout << broi - 1 << endl;
    }
    return 0;
}
