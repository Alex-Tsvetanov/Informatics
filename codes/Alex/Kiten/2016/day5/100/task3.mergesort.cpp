#include <iostream>

using namespace std;

int k = 0;
int arr [10000000];
int n = 7;
int buffer [10000000];

void mergeSort (int left, int right)
{
    int size = right - left;
    if (left == right)
    {
        return;
    }

    if (left + 1 == right)
    {
        if (arr [left] > arr [right])
        {
            swap (arr [left], arr [right]);
            k ++;
        }
    }

    int mid = (left + right) / 2;
    mergeSort (left, mid);
    mergeSort (mid + 1, right);

    int indexLqvo = left;
    int indexDyasno = mid + 1;
    int indexBuffer = 0;

    while (indexLqvo <= mid || indexDyasno <= right)
    {
        if (indexLqvo > mid)
        {
            buffer [indexBuffer] = arr [indexDyasno];
            indexBuffer ++;
            indexDyasno ++;
            continue;
        }

        if (indexDyasno > right)
        {
            buffer [indexBuffer] = arr [indexLqvo];
            indexBuffer ++;
            indexLqvo ++;
            continue;
        }

        if (arr [indexLqvo] <= arr [indexDyasno])
        {
            buffer [indexBuffer] = arr [indexLqvo];
            indexBuffer ++;
            //else cout << "bla" << endl;
            indexLqvo ++;
        }
        else
        {
            buffer [indexBuffer] = arr [indexDyasno];
            indexBuffer ++;
            k += mid + 1 - indexLqvo;
            indexDyasno ++;
        }
    }

    for (int i = 0 ; i < indexBuffer ; i ++)
    {
        arr [left + i] = buffer [i];
    }
}

int main ()
{
    cin >> n;
    for (int i = 0 ; i < n ; i ++)
        cin >> arr [i];
    mergeSort (0, n - 1);
    cout << k << endl;
}
