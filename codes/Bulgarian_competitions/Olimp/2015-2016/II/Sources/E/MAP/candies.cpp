#include<iostream>
using namespace std;
int main ()
{
    int obsht=0,br1=0,brb=0,vurviotnachalo=1,vurviotkrai=0;
    long long A,B,C;
    cin>>A>>B>>C;
    obsht=A+B+C;
    for(int br=0;br<obsht;br++)
    {

     if(br1==0&&A!=0)

     {
         A--;
         brb++;
     if(vurviotkrai==1&&br1==0)
     {
         vurviotkrai=0;
         vurviotnachalo=1;
     }
     }
     else if(br1==0&&A==0)
     {
      br=obsht;
      break;
     }
     if(br1==1&&B!=0)
     {
         B--;
         brb++;
     }
     else if(br1==1&&B==0)
     {
      br=obsht;
      break;
     }
     if(br1==2&&C!=0)
     {
         C--;
         brb++;
        if(vurviotnachalo==1&&br1==2)
     {
         vurviotnachalo=0;
         vurviotkrai=1;
     }
     }
     else if(br1==2&&C==0)
     {
      br=obsht;
      break;
     }
     if(vurviotnachalo==1)
     {
         br1++;
     }
     if(vurviotkrai==1)
     {
         br1--;
     }
    }
    cout<<brb<<endl;
    return 0;
}
