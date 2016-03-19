#include <iostream>
using namespace std;

int main()
{
int N,up=0,down=0;
int rez=0;
cin>>N;

{while (N>0)
{

if (N>2){up=up+1; down=down+2;}
if (N==1) {up=up+1;}
    N=N-3;

}
}
while (down>=4)
{rez=rez+1;
down=down-up;}
cout<<rez<<endl;
 return 0;
}