#include <iostream>
using namespace std;
int main()
{
    long long pov=1, otg=0, br=0;
    char a, b, cpy;
    cin>>b;
    br++;
    cpy=b;
    while(a!='.')
   {
      cin>>a;
      if(a!='.')
      br++;
      if(a==cpy) pov++;
      else
       {
          cpy=a;
          if(pov==1) otg+=0;
          if(pov>1&&pov<10) otg=otg+pov+2;
          if(pov>9&&pov<100) otg=otg+pov+3;
          if(pov>99&&pov<1000) otg=otg+pov+4;
          pov=1;
       }
   }
          if(pov==1) otg+=0;
          if(pov>1&&pov<10) otg=otg+pov+2;
          if(pov>9&&pov<100) otg=otg+pov+3;
          if(pov>99&&pov<1000) otg=otg+pov+4;
   cout<<br-otg<<endl;
    return 0;
}
