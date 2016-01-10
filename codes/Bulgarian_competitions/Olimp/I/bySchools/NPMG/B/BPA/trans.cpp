#include <iostream>

using namespace std;

int main()
{
    unsigned long long P;
    int N, M, K;

    int d = 0;

    cin>>P>>M;



        if(P>10000)
            {
            N = 10000;
            }
        else
            {
            N = P;
            }
    int c[M][2];
    int b[N+1];
    for(int i = 0; i<M; ++i)
        {
        cin>>c[i][1]>>c[i][2];
        }

    cin>>K;

    for(int i = 1; i<=N; ++i)
        {
            b[i] = 0;
        for(int ii = 0; ii<M; ++ii)
            {
            if(c[ii][1] == i || c[ii][2] == i)
                {
                    b[i]++;

                }
            }

        if(b[i] >= K)
            {
            ++d;
            }
        }


    cout<<d<<endl;
    for(int i = 1; i<=N; ++i)
        {
            if(b[i]>=K)
                {
                cout<<i<<" ";
                }
        }
        cout<<endl;
    return 0;
}
