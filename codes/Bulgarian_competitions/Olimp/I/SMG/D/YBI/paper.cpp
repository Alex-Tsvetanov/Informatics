#include<iostream>
using namespace std;
int main()
{
    int M,N,C=0;
    cin>>M>>N;
    while(M!=1)
    {
        if(M%2==1)
        {
            C++;
            M=M-1;
        }
        else
        {
            M=M/2;
            C++;
        }
    }
    while(N!=1)
    {
        if(N%2==1)
        {
            C++;
            N=N-1;
        }
        else
        {
            N=N/2;
            C++;
        }
    }
    cout<<C<<"\n";
    return 0;
}
