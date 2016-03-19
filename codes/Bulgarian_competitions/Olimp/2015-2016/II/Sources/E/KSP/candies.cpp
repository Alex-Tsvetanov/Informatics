#include<iostream>
using namespace std;
int main()
{
    long long A,B,C,i,br;
    cin>>A>>B>>C;
    for (i=0; i<2000000000; i++)
    {
        if (A==0)break;
        A=A-1;
        if (B==0)break;
            B=B-1;
            br++;
        if (C==0)break;
            C=C-1;
            br++;
        if (B==0)break;
            B=B-1;
            br++;

    }
    cout<<br;

}
