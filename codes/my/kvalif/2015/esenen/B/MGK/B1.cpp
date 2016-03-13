#include <iostream>

using namespace std;

int main()
{
    int br, M, x, y, arr1[101], arr2[101], nomer[101], lice[101], k = 0, p = 0;
    cin >> br;

    for (int i = 0; i < br; i++)
    {
        do
        {
            cin >> M;
        }
        while (M < 3 || M > 100);

        for (int j = 0; j < M; j++)
        {
            cin >> x >> y;
            arr1[j] = x;
            arr2[j] = y;
            k++;
        }

        lice[i] = (arr1[k-1] - arr1[k-M]) * (arr2[k-3] - arr2[k-4]);
        k = 0;
        p++;
        nomer[i] = i;
    }
    cout << 0 << endl;

    int min = 1000;
    for (int i = 0; i < p; i++)
    {
        for (int j = i+1; j < p; j++)
        {
            if (lice[j] < lice[i])
            {
                min = lice[j];
                lice[j] = lice[i];
                lice[i] = min;
            }
        }
    }

    cout << lice[0]; //minimalno lice

    return 0;
}
