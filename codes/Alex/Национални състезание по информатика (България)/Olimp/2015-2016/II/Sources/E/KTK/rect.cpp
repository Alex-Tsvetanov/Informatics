#include <iostream>
using namespace std;
int main ()
{
int a,klechki;
cin>>klechki;
if (klechki%2==0) cout<<klechki/11<<endl;
else if (klechki%2>0  or klechki%4>0 or klechki%6>0 or klechki%8>0) cout<<"0"<<endl;
return 0;
}

