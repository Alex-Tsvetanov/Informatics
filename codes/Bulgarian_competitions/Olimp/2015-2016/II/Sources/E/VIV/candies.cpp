#include <iostream>
using namespace std;
int main ()
{
    int t,A,B,C,br=0;
    cin>>A>>B>>C;
    B=A+1;
    while(B!=0)
{
    A--;
    br++;
    B--;
    br++;
    C--;
    br++;
    B--;
    br++;
}
cout<<br-1<<endl;    
return 0;
}