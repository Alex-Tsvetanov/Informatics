#include <iostream>
#include <vector>

using namespace std;

vector<uint64_t> a;
vector<uint64_t> arr;

uint64_t n;

void update (uint64_t x, uint64_t b)
{
    while (x <= n)
    {
        a[x] += b;
        x += x & (-x);
    }
}

uint64_t get (uint64_t x)
{
    uint64_t sum = 0;
    while (x > 0)
    {
        sum += a [x];
        x -= (x & (-x));
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio (false);
    cin.tie (nullptr);
    cin >> n;
    a.resize (n + 2);
    arr.resize (n + 2);
    for (uint64_t i = 1 ; i <= n ; i ++)
    {
        uint64_t b;
        cin >> b;
        arr [i] = b;
        update (i, b);
    }
    uint64_t q;
    cin >> q;
    for (uint64_t i = 0; i < q; i++)
    {
        char ch;
        cin >> ch;
        if (ch == 'u')
        {
            uint64_t b, c;
            cin >> b >> c;
            update(b, c - arr[b]);
            arr[b] = c;
        }
        else
        {
            uint64_t b, c;
            cin >> b >> c;
            cout << get (c) - get (b - 1) << endl;
        }
    }
    return 0;
}
