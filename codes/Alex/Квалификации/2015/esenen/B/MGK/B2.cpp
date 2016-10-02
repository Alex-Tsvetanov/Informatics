#include <iostream>

using namespace std;

int main()
{
    int N;
    do
    {
        cout << "N = ";
        cin >> N;
    }
    while (N <= 1 || N >= 200000);

    int nomer[200001], br_qb[N];

    for (int i = 1; i < N+1; i++)
    {
        nomer[i] = i;
        cin >> br_qb[i];
    }

    int krai;
    do
    {
        cin >> krai;
    }
    while (krai > N);

    int cons = 0;
    int M;
    for (int i = 1; i <= krai; i+=M)
    {
        do
        {
            cout << "Razmer na skok = ";
            cin >> M;
        }
        while (M <= 0 || M >= 200);

        cons += br_qb[i];
    }

    cout << cons << " " << krai;

    return 0;
}
