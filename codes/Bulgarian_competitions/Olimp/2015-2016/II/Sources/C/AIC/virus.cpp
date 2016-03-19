#include <iostream>

using namespace std;

int IdontKnow = (1<<30);

long long find_k (long long n)
{
    switch (n)
    {
    case 2:
        return 1;
    case 3:
        return 1;
    case 4:
        return 2;
    case 5:
        return 3;
    case 6:
        return 4;
    case 7:
        return 4;
    case 8:
        return -1;
    case 9:
        return 6;
    case 10:
        return 6;
    }
    if (n % 3 == 0)
        return n / 3 * 2 - 1;
    if (n % 3 == 1)
        return find_k (n - 1);
    if (n % 3 == 2)
        return IdontKnow;
}

void find_path (long long n)
{
    switch (n)
    {
    case 2:
        cout << "1 1\n";
        return ;
    case 3:
        cout << "2 1 2\n";
        return ;
    case 4:
        cout << "2 1 2\n2 2 3\n";
        return ;
    case 5:
        cout << "2 3 5\n4 1 2 3 5\n3 2 4 5\n";
        return ;
    case 6:
        cout << "2 1 2\n2 2 3\n2 4 5\n2 5 6\n";
        return ;
    case 7:
        cout << "2 1 2\n2 2 3\n2 4 5\n2 5 6\n";
        return ;
    case 8:
        cout << "-1\n";
        return ;
    case 9:
        cout << "2 1 2\n2 2 3\n2 4 5\n2 5 6\n2 7 8\n2 8 9\n";
        return ;
    case 10:
        cout << "2 1 2\n2 2 3\n2 4 5\n2 5 6\n2 7 8\n2 8 9\n";
        return ;
    }
    if (n % 3 == 0)
    {
        for (int i = 0 ; i < n / 3 ; i ++)
            cout << "2 " << i * 3 + 1 << " " << i * 3 + 2 << "\n"
                 << "2 " << i * 3 + 2 << " " << i * 3 + 3 << "\n";
        return;
    }
    if (n % 3 == 1)
        find_path (n - 1);
    if (n % 3 == 2)
        return ;
}

int main ()
{
    cin.tie (NULL);
    ios::sync_with_stdio (false);
    long long n;
    long long k;
    cin >> n;
    k = find_k (n);
    cout << k << "\n";
    if (n > 500)
        return 0;
    find_path (n);
    return 0;
}

