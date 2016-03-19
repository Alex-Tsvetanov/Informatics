#include <iostream>
using namespace std;
int main ()
{
    long long A,B,C,br=0;
    cin>>A>>B>>C;
    while (A!=0 or B!=0 or C!=0)
    {
        if (A==1) br=br+1;
        if (B==1) br=br+2;
        if (C==1) br=br+3;
        if (A<B and A<C) br=br+(A*2)+(A/2);
        if (B<A and B<C) br=br+(B*2)+(B/2);
        if (C<A and C<B) br=br+(C*2)+(C/2);
        if (A==0 or B==0 or C==0) break;
    }
    cout<<br<<endl;
    return 0;
}
