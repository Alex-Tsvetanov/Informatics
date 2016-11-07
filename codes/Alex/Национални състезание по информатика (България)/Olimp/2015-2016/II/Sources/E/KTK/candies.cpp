#include <iostream>
using namespace std;
int main ()
{
long long a,b,c;
int i,br;
cin>>a>>b>>c;
while (a>0 or b>0 or c>0)
{
a--;
if (a-1>1) br++;
else break;
b--;
if (b-1>1) br++;
else break;
c--;
if (c-1>1) br++;
else break;
}
cout<<br<<endl;
return 0;
}
