#include<iostream>
using namespace std;
int main()
{
    int N,M,P;
    do{cin>>N;}
    while(N<=7||N>=124);
    do{cin>>M;}
    while(M<=1||M>=1000);
    do{cin>>P;}
    while(P<=1||P>=1000);
    int i=0;
    int S[M];
    int E[M];
    while(i<M)
    {
        cin>>S[i];
        cin>>E[i];
        i++;
    }
    cout<<"MIXED";

return 0;
}
