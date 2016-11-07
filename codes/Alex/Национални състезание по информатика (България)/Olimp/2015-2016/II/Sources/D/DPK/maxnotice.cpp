#include<iostream>
using namespace std;
int main ()
{
    int L,H,N,A,B,X,Y,S1;
    cin>>L>>H;
    cin>>N;
    int S[N+1];
    S[0] = L*H;
    int T[L][H];
    for (int i = 1;i <= N;i++)
    {
        cin>>X>>Y>>A>>B;
        S[i] = A*B;
    }
    S1 = S[0];
    for (int i = 1;i <=N;i++)
    {
        S1 = S1 - S[i];
    }

    cout<< S1;
    return 0;
}
