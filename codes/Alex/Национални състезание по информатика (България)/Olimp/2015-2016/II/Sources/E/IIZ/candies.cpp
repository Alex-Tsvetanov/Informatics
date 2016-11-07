#include <iostream>
using namespace std;
int main()
{
    int A,B,C,d=0,a1,b1,c1;
    cin>>A>>B>>C;
    a1=A-1; b1=B-1; c1=C-1; d=d+3;
    if(A==B && A==C && B==C)
    {while (a1 || b1 || c1>1)
    {
        a1--;
        b1--;
        c1--;
        d++;
    }
    }
     if(A!=B || A!=C || B!=C)
     {
         while(b1>1)
         {
             a1--;
             b1--;
             c1--;
             d++;
         }
     }
     if(A==B==C==1)cout<<"3"<<endl;
     if(A==B==C==2)cout<<"5"<<endl;
     if(A!=B || A!=C || B!=C && B!=1)cout<<d+1<<endl;
     if(A!=B || A!=C || B!=C && B==1)cout<<d<<endl;
     else cout<<d+2<<endl;
    return 0;
}
