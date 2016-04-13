#include <iostream>

using namespace std;

int* arr;

void exchange (int i, int j)
{
    int tmp = arr [i];
    arr [i] = arr [j];
    arr [j] = tmp;
}
void assign (int ndx, int val)
{
    arr [ndx] = val;
}

int compare (int ind1, int ind2)
{
    if (arr [ind1] < arr [ind2]) return -1;
    if (arr [ind1] > arr [ind2]) return  1;
    if (arr [ind1] == arr [ind2])return  0;
    return 1912929;
}

int lower (int from, int to, int val)
{
    int len = to - from, half;
    while (len > 0)
    {
        half = len/2;
        int mid= from + half;
        if (compare (mid, val) < 0)
        {
            from = mid+1;
            len = len - half -1;
        }
        else len = half;
    }
    return from;
}

int upper (int from, int to, int val)
{
    int len = to - from, half;
    while (len > 0)
    {
        half = len/2;
        int mid= from + half;
        if (compare (val, mid) < 0)
            len = half;
        else
        {
            from = mid+1;
            len = len - half -1;
        }
    }
    return from;
}

void insert_sort (int from, int to)
{
    if (to > from+1)
    {
        for (int i = from+1; i < to; i++)
        {
            for (int j = i; j > from; j--)
            {
                if (compare(j, j-1)<0)
                    exchange(j, j-1);
                else break;
            }
        }
    }
}

int gcd (int m, int n)
{
    while (n!=0)
    {
        int t = m % n;
        m=n;
        n=t;
    }
    return m;
}

void reverse (int from, int to)
{
    while (from < to)
    {
        exchange(from++, to--);
    }
}

void rotate (int from, int mid, int to)
{
    if (from==mid || mid==to) return;
    int n = gcd(to - from, mid - from);
    while (n-- != 0)
    {
        int val = arr [from + n];
        int shift = mid - from;
        int p1 = from+n, p2=from+n+shift;
        while (p2 != from + n)
        {
            assign(p1, arr [p2]);
            p1=p2;
            if ( to - p2 > shift) p2 += shift;
            else p2=from + (shift - (to - p2));
        }
        assign(p1, val);
    }
}

void merge(int from, int pivot, int to, int len1, int len2)
{
    if (len1 == 0 || len2==0) return;
    if (len1+len2 == 2)
    {
        if (compare(pivot, from) < 0)
            exchange(pivot, from);
        return;
    }
    int first_cut, second_cut;
    int len11, len22;
    if (len1 > len2)
    {
        len11=len1/2;
        first_cut = from + len11;
        second_cut = lower(pivot, to, first_cut);
        len22 = second_cut - pivot;
    }
    else
    {
        len22 = len2/2;
        second_cut = pivot + len22;
        first_cut = upper(from, pivot, second_cut);
        len11=first_cut - from;
    }
    rotate(first_cut, pivot, second_cut);
    int new_mid=first_cut+len22;
    merge(from, first_cut, new_mid, len11, len22);
    merge(new_mid, second_cut, to, len1 - len11, len2 - len22);
}

void sort(int from, int to)
{
    if (to - from == 1)
    {
        return;
    }
    int middle = (from + to)/2;
    sort (from, middle);
    sort (middle, to);
    merge(from, middle, to, middle-from, to - middle);
}

int main ()
{
    int n;
    cin >> n;
    arr = new int [n];
    for (int i = 0 ; i < n ; i ++)
        cin >> arr [i];
    sort (0, n);
    for (int j = 0 ; j < n ; j ++)
        cout << arr [j] << " ";
    cout << "\b\n";
}
