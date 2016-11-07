#include<iostream>
using namespace std;
int main()
{
    long long A,B,C,br=0;
    cin>>A>>B>>C;
    if(A!=0&&B!=0&&C!=0)br++;
    else if(A==0&&B==0&&C==0)br;
    cout<<br<<"\n";
    return 0;
}
