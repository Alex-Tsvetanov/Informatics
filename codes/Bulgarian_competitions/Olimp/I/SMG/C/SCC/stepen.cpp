//Stefania Tsvetanova Tsvetkova
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector <pair <int, int> > res;
long long osnova, stepen_na_osnovata = 1;

void nameri_osnovata (long long X)
{
    for (int i = 2; i <= sqrt(X); ++i)
    {
        //cout << i << " " << X << " " << (X % i) << endl;
        if (X % i == 0)
        {
            long long a = i;
            while (a < X)
            {
                a *= i;
                ++stepen_na_osnovata;
            }
            if (a == X)
            {
                osnova = i;
                return;
            }
            osnova = 0;
            stepen_na_osnovata = 1;
            //cout << osnova << " ; " << stepen_na_osnovata << endl;
        }
    }
}

int main ()
{
    //cout << (((int)sqrt(2) * (int) sqrt(2)) == 2) << endl;
    long long X;
    cin >> X;

    nameri_osnovata(X);
    //cout << "osnova " << osnova << " stepen na osnovata " << stepen_na_osnovata << endl;

    if (osnova == 0)
    {
        cout << "0\n";
        return 0;
    }

    long long a = 1, b = stepen_na_osnovata;
    while (b >= 2)
    {
        //cout << "a b " << a << " " << b << endl;
        long long curr = osnova, seg_osnova;
        for (int j = 1; j < a; ++j)
        {
            curr *= osnova;
        }
        seg_osnova = curr;
        for (int j = 1; j < b; ++j)
        {
            seg_osnova *= curr;
        }
        if (seg_osnova == X)
            res.push_back(make_pair(curr, b));
        /*curr = osnova;
        for (int j = 1; j < b; ++j)
        {
            curr *= osnova;
        }
        seg_osnova = curr;
        for (int j = 1; j < a; ++j)
        {
            seg_osnova *= curr;
        }
        if (seg_osnova == X)
            res.push_back(make_pair(curr, a));*/
        b /= 2;
        a *= 2;
    }

    cout << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; --i)
    {
        if (res[i].first != X)
            cout << res[i].first << ' ' << res[i].second << '\n';
    }
    return 0;
}
