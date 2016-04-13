#include <iostream>

using namespace std;

int abs(int a)
{
    if (a < 0)
        return -a;
    else
        return a;
}

int main()
{
    int N;
    cin >> N;
    int a[N];

    int br = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            br++;
            if (br == N)
            {
                cout << 1 << " " << 2;
                return 0;
            }
        }
    }

    int max = -100, sum, p, q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i+1; j <= N; j++)
        {
            sum = a[j] - a[i];
            if (abs(sum) >= max)
            {
                max = abs(sum);
            }
        }
    }

    int maxi = -1000, mini = 1000;
    for (int i = 1; i <= N; i++)
    {
        for (int j = i+1; j <= N; j++)
        {
            sum = a[j] - a[i];
            if (abs(sum) == max)
            {
                if (j - i >= maxi)
                {
                    maxi = j - i;
                    p = i;
                    q = j;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = i+1; j <= N; j++)
        {
            sum = a[j] - a[i];
            if (abs(sum) == max)
            {
                if (j - i == maxi)
                {
                    if (i + j <= mini)
                    {
                        mini = i + j;
                        p = i;
                        q = j;
                    }
                }
            }
        }
    }

    cout << p << " " << q;
    cout << endl;

    return 0;
}
