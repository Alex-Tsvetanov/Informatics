#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
 int a,b,c,d=0;
cin>>a>>b>>c;
while(a!=0 and b>1 and c!=0)
{

    d=d+4;
    a--;
    b=b-2;
    c--;

}
if(a>0 and b>0 and c==0){a--;b--;d=d+2; cout<<d<<endl;}
if(a>0 and b==0){a--;d++; cout<<d<<endl;}
if(a>0 and b>0 and c>0){a--;b--;c--;d=d+3; cout<<d<<endl;}



return 0;
}
