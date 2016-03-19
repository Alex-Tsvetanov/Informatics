#include <iostream>
using namespace std;
int main()
{
  long long A, B, C, d, br=0;
  cin>>A>>B>>C;
  while(A!=0 or B!=0 or C!=0)
    {
        if(A-1>=0) br=br+1;
        if(B-1>=0) br=br+1;
        if(C-1>=0) br=br+1;
        if (A==0 or B==0 or C==0) break;
    }
    cout<<br<<endl;
   return 0;
}
