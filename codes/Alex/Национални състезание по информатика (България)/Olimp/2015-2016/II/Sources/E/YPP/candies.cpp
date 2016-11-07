#include<iostream>
using namespace std;

int main()
{
   int a,b,c,p=0;
   cin >> a >> b >> c;
   for(int i=a+b+c;i>0;i--)
   {
     if(a-1>=0)
     {
       a--;
       p++;
     }
     else i=0;

     if(b-1>=0)
     {
       b--;
       p++;
     }
     else i=0;

     if(c-1>=0)
     {
       c--;
       p++;
     }
     else i=0;

     if(b-1>=0)
     {
      b--;
      p++;
     }
     else i=0;
   }
   cout << p << endl;




  return 0;
}
