#include <iostream>

using namespace std;

char Map [100][100];
bool rowIsFull [100];

int main ()
{
    cin.tie (nullptr);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    for (int i = 0 ; i < N ; i ++)
    {
        rowIsFull [i] = true;
        for (int j = 0 ; j < M ; j ++)
        {
            cin >> Map [i][j];
            rowIsFull [i] = rowIsFull [i] and (Map [i][j] == '*');
        }
    }

    int sum = 0;
    for (int k = 0 ; k < N ; )
    {
        int curr = 0;
        for (int i = N - k - 1 ; i >= 0 ; i --)
        {
            if (rowIsFull [i] == 0)
                break;
            curr += rowIsFull [i];
        }

        sum += curr * (curr + 1) / 2;
        k += (curr == 0)?1:curr;
    }

    cout << sum << "\n";
}

