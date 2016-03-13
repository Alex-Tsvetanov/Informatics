#include <iostream>

using namespace std;

int main()
{
    long long T[3], N, n;

    N = 0;
    for (n = 0; n < 3; n++) {
        T[n] = -2000000001;
    }
    for (n = 0; n < 3; n++) {
        while ((T[n] < -2000000000) || (T[n] > 2000000000)) {
            cin >> T[n];
        }
    }
    while ((N < 1) || (N > 20)) {
        cin >> N;
    }
    for (n = 3; n < N; n++) {
        T[n] = T[n - 1] + T[n - 2] + T[n - 3];
        cout << T[N - 2] + T[N - 3] + T[N - 4];
    }
    for (n = 0; n < 3; n++) {
        if (T[N - 1] == T[n]) {
            cout << T[n];
            break;
        }
    }
    return 0;
}
