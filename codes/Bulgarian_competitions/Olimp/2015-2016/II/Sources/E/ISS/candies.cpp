#include <iostream>
using namespace std;
int main ()
{
long long A, B, C;
long long br=0;
cin>>A>>B>>C;
while (B!=0&&A!=0&&C!=0)
{
 A=A-1;
 br++;
 B=B-1;
 br++;
 C=C-1;
 br++;
 if (B!=0)
 {
     B=B-1;
     br++;
 }
}
cout<<br<<endl;

return 0;
}
