#include <iostream>
using namespace std;
int main()
{
    int A,B,C,cntr=0;
    cin>>A>>B>>C;
    B=A+1;
    while(B!=0)
    {
        A--;
        cntr++;
        B--;
        cntr++;
        C--;
        cntr++;
        B--;
        cntr++;
    }
    cout<<cntr-1<<endl;
    return 0;
}