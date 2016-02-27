#include<iostream>
using namespace std;
int main ()
{
    long long N, M = 0, nn, mid, nn1, one = 1;
    char Mchar;
    cin >> N;
    mid = N / 2 + 1;
    nn = N;
    nn1 = nn;
    char Nchar[N];
    while (N > 0)
    {
        cin >> Nchar[N];
        N--;
    }
    if (N == 0)
    {
        if (Nchar[nn] != Nchar[1])
        {
            if (mid % 2 == 0)
            {
                if (Nchar[mid - 1] == Nchar[mid + 1])
                {
                    Mchar = Mchar;
                    M = M;
                }
                else
                {
                    M = nn - 2;
                    cout << M << endl;
                    while (1 < nn)
                    {
                        cout << Nchar[one + 1];
                        nn--;
                        one++;
                    }
                }
            }
            else
            {
                cout << 1 << endl;
                cout << Nchar[nn1];
            }
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}
