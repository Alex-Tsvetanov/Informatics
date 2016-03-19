#include <iostream>

using namespace std;

int main()
{
    int N = 0, M = 0, P = 0;
    cin >> N >> M >> P;

    int nCin;

    for (int i = 0; i < M*2; i++)
        cin >> nCin;

    if (N < M*(P/2))
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else
    {
        cout << "MIXED" << endl;
        return 0;
    }

    return 0;
}
