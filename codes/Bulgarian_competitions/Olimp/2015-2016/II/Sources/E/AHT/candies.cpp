#include <iostream>
using namespace std;
int main ()
    {
   long long A,B,C,id=2,ot=1,i=0,k=8;
   cin>>A>>B>>C;
   while(k==k)
   {
       if(ot==1 && A==0)break;

       if(ot==2 && B==0)break;

       if(ot==3 && C==0)break;

       if(id==2 && ot==1){ id=1; ot=2;i++;A--;}
       if(ot==1 && A==0)break;

       if(ot==2 && B==0)break;

       if(ot==3 && C==0)break;

       if(ot==2){
       if(id==1){id=2;ot=3;i++;B--; }
       if(id==3){id=2;ot=1;i++;B--; }
       }
       if(ot==1 && A==0)break;

       if(ot==2 && B==0)break;

       if(ot==3 && C==0)break;

       if(id==2 && ot==3){i++;ot=2;id=3;C--;}
   }
   cout<<i<<endl;
    return 0;
    }
