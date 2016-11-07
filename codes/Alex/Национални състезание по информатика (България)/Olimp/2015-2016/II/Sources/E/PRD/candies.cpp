#include<iostream>
using namespace std;
int main()
{
    long long A,B,C;
    int br=0;
    cin>>A>>B>>C;
    while((A!=0)||(B!=0)||(C!=0))
    {
        if(A==0) break;
        else A=A-1;br++;
        if(B==0)break;
        else B=B-1;br++;
        if(C==0)break;
        else C=C-1;br++;
        if(B==0)break;
        else B=B-1;br++;
    }
    cout<<br<<endl;
    return 0;
    }
