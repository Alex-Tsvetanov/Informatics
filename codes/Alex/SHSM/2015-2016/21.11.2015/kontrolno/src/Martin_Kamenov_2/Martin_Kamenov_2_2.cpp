#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long b;
    cin >> b;
    long long a, c;

    int i = 0;
    int arr[1000], arr2[1000];
    while (b != 0)
    {
        arr[i] = b%10;
        arr2[i] = b%10;
        b /= 10;
        i++;
    }

    int max = -1, min = 100;
    for (int j = 0; j < i; j++)
    {
        for (int k = j+1; k < i; k++)
        {
            if (arr[k] > max)
            {
                max = arr[k];
                arr[k] = arr[j];
                arr[j] = max;
            }
        }
    }

    sort (arr2, arr2 + i);

    for (int j = 0; j < i; j++)
    {
        cout << arr[j];
    }
    cout << endl;

    for (int j = 0; j < i; j++)
    {
        cout << arr2[j];
    }

    return 0;
}
