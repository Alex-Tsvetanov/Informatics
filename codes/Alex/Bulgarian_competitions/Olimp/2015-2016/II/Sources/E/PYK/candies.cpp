#include<iostream>
using namespace std;
int main()
{
    int A,B,C;
    cin>>A>>B>>C;
    int spane=A==0+B+C||A+B==0+C||A+B+C==0;
    cout<<spane<<endl;

     return 0;
}
