#include <iostream>
#include <ctype.h>
using namespace std;
int main ()
{
   char a,x;
long long ch=0,br=0;


    cin.get(a);x=a;
   while(a!='.')
   {
       cin.get(a);br++;
        if(x==a){ch++;br++;x=a;}
   }
   if(br>ch) swap(br,ch);
   cout<<ch-br-1<<endl;
   return 0;
}

