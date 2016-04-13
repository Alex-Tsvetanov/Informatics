#include<iostream>
using namespace std;
int main ()

{
   long long A,B,C,e=0,f=0,g=0;
   cin>>A>>B>>C;
   if (A!=0)
   A=A-1;
   e=e+1;
   if (B!=0)
   B=B-1;
   f=f+1;
   if (C!=0)
   C=C-1;
   g=g+1;
   while (A!=0&&B!=0&&C!=0)
   {
   if (B!=0)
   B=B-1;
   f=f+1;
   if (A!=0)
   A=A-1;
   e=e+1;
   if (B!=0)
   B=B-1;
   f=f+1;
   if (C!=0)
   C=C-1;
   g=g+1;
   }
   cout<<e+f+g<<endl;
   return 0;
} 