#include <iostream>
using namespace std;
int main()
{
  int sv,L,i,H,N,a1,a,b,a2,a3,a4;
  int arr[200][200];
    cin>>L>>H;
    cin>>N;
    sv=H*L;
    for(i=1;i<=N;i++)
    {
     cin>>a1>>a2>>a3>>a4;
     sv=sv-a3*a4;
    }
 cout<<sv/2+3;
 return 0;
}
