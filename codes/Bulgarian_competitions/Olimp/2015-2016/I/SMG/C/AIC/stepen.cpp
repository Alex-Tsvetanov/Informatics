#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

const int maxX = 1000000000;

vector < pair < int, int > > ans;

int main ()
{
    cin.tie (nullptr);
    ios::sync_with_stdio(false);
    int X;
    cin >> X;

    ///*
    for (int a = sqrt (X) ; a >= 2 ; a --)
    {
        int b;
        int POW = a * a;
        for (b = 2 ; (POW < X) and (X % POW == 0) ; b ++, POW *= a) {}
        if (POW == X)
            ans.push_back ({a, b});
    }

    cout << ans.size () << "\n";
    for (int i = 0 ; i < (int)ans.size () ; i ++)
        cout << ans [i].first << " " << ans [i].second << "\n";
}
