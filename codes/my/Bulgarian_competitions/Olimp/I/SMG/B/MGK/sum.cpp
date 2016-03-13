#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int del = 0;
    for (int j = 1; j <= N; j++)
    {
        if (N % j == 0)
        {
            del++;
            if (j == N && del == 2)
            {
                cout << N - 1 << endl;
                return 0;
            }
            else
            {
                if (j == N && del > 2)
                {
                    cout << N + 1 << endl;
                    return 0;
                }
            }
        }
    }

    return 0;
}
