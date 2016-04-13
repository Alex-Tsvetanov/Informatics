#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int P, M, K;
    cin >> P >> M;

    int a[2*M], b[2*M];
    for (int i = 0; i < 2*M; i++)
    {
        cin >> a[i];
    }

    cin >> K;

    int br = 1, yay = 0, p = 0, df = 0;
    for (int i = 0; i < 2*M; i++)
    {
        for (int j = i+1; j < 2*M; j++)
        {
            if (a[i] == a[j])
            {
                br++;
            }
        }
        if (br >= K)
        {
            b[p] = a[i];
            p++;
            yay++;
        }
        for (int l = i+1; l < 2*M; l++)
        {
            if (a[l] == a[i])
            {
                df++;
            }
        }
        if (df >= 2)
            i++;

        br = 1;
        df = 0;
    }

    cout << yay << endl;

    sort (b, b+p);
    for (int i = 0; i < p; i++)
    {
        cout << b[i] << " ";
        if (b[i+1] == b[i])
        {
            i++;
        }
    }
    cout << endl;
    return 0;
}
