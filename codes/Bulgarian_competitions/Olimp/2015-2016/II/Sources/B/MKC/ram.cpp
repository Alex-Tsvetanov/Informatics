#include <iostream>
using namespace std;
long long mas[50000000];
int main ()
{
long long K, M, N, SUM, maskey=1, br=0;
cin>>K;
for (M=1; 1; M++)
{
    for (N=1; 1; N++)
    {
        if (M*(N+1)+N*(M+1)-K<0) continue;
        if (N>M)
        {
            if (M*(N+1)+N*(M+1)-K==M+M)
            {
                br++;
                mas[maskey]=M;
                mas[maskey+1]=N;
                maskey=maskey+2;
                break;
            }
            if (M*(N+1)+N*(M+1)-K>M+M) break;
        }
        if (N<=M)
        {
            if (M*(N+1)+N*(M+1)-K==N+N-1)
            {
                br++;
                mas[maskey]=M;
                mas[maskey+1]=N;
                maskey=maskey+2;
                break;
            }
            if (M*(N+1)+N*(M+1)-K>N+N-1) break;
        }

    }
        if (M*2+2*(M+1)-K>N+N-1) break;
}
    cout<<br<<endl;
    int p=1;
    while (1)
    {
        if (mas[p]==0) break;
            cout<<mas[p]<<" "<<mas[p+1]<<endl;
            p=p+2;
    }
return 0;
}
