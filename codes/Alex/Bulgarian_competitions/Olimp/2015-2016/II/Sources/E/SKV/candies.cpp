#include<iostream>
using namespace std;
int main()
{
    int A,B,C,i,a,b,c,n,br=0;
    cin>>A>>B>>C;
    a=A;
    b=B;
    c=C;
    n=A+B+C;
    for(i=1;i<n;i++)
    {
        A=A-1;
        B=B-1;
        C=C-1;
        br=br+3;
        if(A<=0)
        break;
        else if(B<0)
        break;
        else if(C<=0)
        break;

    }
    cout<<br-1<<endl;
    return 0;
}
