#include <iostream>
using namespace std;

int main()
{
    bool signMini = false, signMaxi;
    int N, mini, maxi, br2, br , br3, br4, temp, temp2; // br - indexi (br & br2) - 1V (br3 & br4) - 2V;
    cin >> N;

    int arr[N];
    cin >> arr[0];
    mini = arr[0];
    maxi = arr[0];
    for (int i = 1; i<N ; i++)
    {
        cin >> arr[i];
        if(mini > arr[i])
            mini = arr[i];
        if(maxi < arr[i])
            maxi = arr[i];
    }

    for (int i = 0; i<N ; i++)
    {
        if(arr[i] == mini || arr[i] == maxi)
        {
            br = i;
            temp = arr[i];
            break;
        }
    }

    if(temp == mini)
    {
        temp2 = maxi;
    }
    if(temp == maxi)
    {
        temp2 = mini;
    }

    for (int i = 0; i<N ; i++)
    {
        if(arr[i]== temp2)
        {
            br3 = i;
            break;
        }
    }
    // v1
    for (int i = N; i>= br ; i--)
    {
        if(arr[i] == temp2)
        {
            br2 = i;
            break;
        }
    }
    // v2
    for (int i = N; i>= br ; i--)
    {
        if(arr[i] == temp)
        {
            br4 = i;
            break;
        }
    }
    (br4 - br3)>(br2-br)? cout << br3+1 << " " << br4+1 << endl : cout << br+1 << " " << br2+1 << endl;
}
