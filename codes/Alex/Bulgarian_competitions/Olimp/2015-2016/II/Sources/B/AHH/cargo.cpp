#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    bool mixed = false, impossible = false;
    int N ,M, P, S1, S2;

    cin >> N >> M >> P;
    if(N < 1000000)
    {
    int days[N];
    for(int i = 0; i < N; i++)
        days[i] = 0;
    P/=2;
    if(M/P > N){
        impossible = true;
    }
    for(int i = 0; i < M; i++)
    {
        cin >> S1 >> S2;
        if(impossible)
            continue;
        for(int j = S1-1; j < S2; j++)
        {
            if(days[j] < P)
            {
                if((j+1)%6 == 0 || (j+1) % 7 == 0)
                    mixed = true;
                days[j]++;
                break;
            }
            if(j == S2)
            {
                cout << i << endl;
                impossible = true;
            }
        }
    }
    if(impossible)
        cout << "IMPOSSIBLE" << endl;
    else if(mixed)
        cout << "MIXED" << endl;
    else
        cout << "OK" << endl;
    }else
    {
        for(int i = 0; i < M; i++)
        {
            cin >> S1 >> S2;
        }
        cout << "OK" << endl;
    }
}






















