#include <iostream>
#include <string>

using namespace std;

int primes [3000];
bool vis [100000];

void fill ()
{
    vis [0] = vis [1] = 1;
    for (int i = 2 ; i < 100000 ; i ++)
        if (vis [i] == 0)
            for (int j = 2 * i ; j < 100000 ; j += i)
                vis [j] = 1;

    int ind = 0;
    for (int i = 2 ; i < 100000 and ind < 3000 ; i ++)
        if (vis [i] == 0)
            primes [ind++] = i;
}

int main ()
{
    cin.tie (nullptr);
    ios::sync_with_stdio(false);
    string a;
    cin >> a;
    fill ();
    int sum = 0;
    for (int i = 0 ; i < (int)a.size () ; i ++)
        sum += primes [i] * (a [i] - '0');
    cout << sum << "\n";
}
