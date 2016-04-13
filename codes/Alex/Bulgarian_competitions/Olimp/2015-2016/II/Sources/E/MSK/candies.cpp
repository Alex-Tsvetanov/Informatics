#include <iostream>
using namespace std;
int main ()
{
   long long a,b,c,i=0,br=0;
   cin>>a>>b>>c;
   for(i=0;i<a+b+c;i++)
   {
       if(a==1&&b==1&&c==1||a==1&&b==1&&c>1||a==1&&b>1&&c>1) br=3;
      a=a-1;
    if((a==0&&b>1)||(a>1&&b>1))
    {if(a>1&&b>1) {br++;b=b-1;if(b!=0)br++;else break;c=c-1;if(c!=0)br++;else break;}else break;}
        else break;
    }
     cout<<br;
   return 0;
}

