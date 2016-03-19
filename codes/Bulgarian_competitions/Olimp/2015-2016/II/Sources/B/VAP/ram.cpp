#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long K = 0;
    cin >> K;

    vector<int> vecCout;

    for (long long M = 1; M < K/3; M++)
    {
        if ((M - K + 1)%(1 - 2*M) == 0 && M >= (M - K + 1)/(1 - 2*M) && (M - K + 1)/(1 - 2*M) > 0)
        {
            vecCout.push_back(M);
            vecCout.push_back((M - K + 1)/(1 - 2*M));
        }

        if ((M + K)%(1 + 2*M) == 0 && M < (M + K)/(1 + 2*M) && (M + K)/(1 + 2*M) > 0)
        {
            vecCout.push_back(M);
            vecCout.push_back((M + K)/(1 + 2*M));
        }
    }

    if (vecCout.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        cout << vecCout.size()/2 << endl;

        for (int i = 0; i < vecCout.size()/2; i++)
            cout << vecCout[2*i] << " " << vecCout[2*i + 1] << endl;
    }

    return 0;
}
