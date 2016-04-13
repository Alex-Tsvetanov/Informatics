#include<iostream>
#include<math.h>
using namespace std;
int main()
{
   long long N;
   cin>>N;
   for(long long  i=sqrt(N);i>0;i--)
   {
       if(N%i==0)
       {
          //cout<<i<<"x"<<N/i<<"="<<2*(i+N/i)<<"\n";
          cout<<2*(i+N/i)<<"\n";
          break;
       }
   }
   return 0;
}
