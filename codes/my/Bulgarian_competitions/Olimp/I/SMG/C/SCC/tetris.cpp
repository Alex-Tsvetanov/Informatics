//Stefania Tsvetanova Tsvetkova
#include <iostream>
#include <string>

using namespace std;

unsigned N, M;

int main ()
{
    cin >> N >> M;
    unsigned curr = 0,  res = 0;
    for (unsigned i = 0; i < N; ++i)
    {
        string c;
        cin >> c;
        bool OK = true;
        for (int j = 0; j < M; ++j)
        {
            if (c[j] != '*')
                OK = false;
        }
        if (OK)
            ++curr;
        else
        {
            res += curr * (curr + 1) / 2;
            curr = 0;
        }
    }

    if (curr > 0)
        res += curr * (curr + 1) / 2;

    cout << res << '\n';
    return 0;
}
