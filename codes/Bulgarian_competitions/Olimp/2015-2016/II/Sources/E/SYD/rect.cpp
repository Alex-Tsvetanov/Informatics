#include<iostream>
using namespace std;
int main ()
{
   long long N,a,b,s,br=0;
   cin>>N;
   a=1||br++;
   b=1||br++;
   s=N-((a+b)*2);
   N=(a+b)*2+s;
   if(s==N-((a+b)*2))cout<<0<<endl;
   else cout<<br<<endl;
   return 0;
}