#include <iostream>
using namespace std;
int main()
{
    long long A,B,C,i=0;
    cin>>A>>B>>C;
    while(A!=0||B!=0||C!=0)
    {
        if(A==0) break;
        A--;i++;
        if(B==0) break;
        B--;i++;
        if(C==0) break;
        C--;i++;
        if(B==0) break;
        B--;i++;
    }
    cout<<i<<endl;
    return 0;
}

