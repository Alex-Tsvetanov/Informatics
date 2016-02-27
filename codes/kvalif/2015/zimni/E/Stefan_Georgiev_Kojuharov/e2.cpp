#include <iostream>
using namespace std;
int main()
{
 long long T1,T2,T3,N,Tn,segashen=0,predishen=0;
 cin>>T1>>T2>>T3;
 for(int i=0;i<N;i++);
 {
  segashen=(predishen-1)+(T1-2)+(T2-3);
  predishen=(T1-1)+(T2-2)+(T3-3);
  if(segashen>predishen)
  {
  Tn=segashen-predishen;
  }
  if(predishen>segashen)
  {
  Tn=predishen-segashen;
  }

  }
 cout<<Tn<<endl;
 cout<<endl;
 return 0;
 }
