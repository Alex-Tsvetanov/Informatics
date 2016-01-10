#include<iostream>
using namespace std;
int main()
{
    int A,B,G,R,c;

    cin>>A>>B;

    R=A+B;

    c=(R%100)/10;

    if (c==0) cout<<R-100<<endl<<R<<endl;
    else cout<<R-10<<endl<<R<<endl;

    return 0;
}
