#include <iostream>
using namespace std;
int main ()
    {
   long long i=0,br=0,br1=0;
   char se,pr=0;
   while(se!='.')
   {
       cin>>se;
       if(se==pr)i++;
       else
       if(i==0)br++;
       else {br+=2; i=0;}
       br1++;
       pr=se;}
       cout<<br1-br<<endl;
    return 0;
    }

