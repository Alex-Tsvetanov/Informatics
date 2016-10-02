#include<iostream>
using namespace std;
int main ()
{
    long long N = 4, chislo, broi;
    long long T[N];
    cin >> T[1] >> T[2] >> T[3] >> broi;
    while (N < broi + 1)
    {
        T[N] = T[N - 1] + T[N - 2] + T[N - 3];
        if (N == broi)
        {
            chislo = T[N - 1] + T[N - 2] + T[N - 3];
        }
        N++;
    }
    if (broi == 1)
    {
        cout << T[1] << endl;
    }
    if (broi == 2)
    {
        cout << T[2] << endl;
    }
    if (broi == 3)
    {
        cout << T[3] << endl;
    }
    if (broi != 1 and broi != 2 and broi != 3)
    {
        cout << chislo << endl;
    }
    return 0;
}
