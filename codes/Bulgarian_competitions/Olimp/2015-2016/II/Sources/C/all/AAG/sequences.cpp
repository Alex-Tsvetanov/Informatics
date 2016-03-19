#include <iostream>
using namespace std;
long long p,n,s,br=0,a[100];
void bt(int cs,int ci)
{
 int i,x;
 if(cs<s)
  if(ci==n+1)
  {
       /*cout<<cs<<"----";
       for(i=1;i<=n;i++)
        cout<<a[i]<<" ";
       cout<<endl;*/
       br++;
  }
 if(cs<s)
  {
   for(i=0;i<p;i++)
   {

       if(i<s-cs && ci<=n)
       {
        //a[ci]=i;
        bt(cs+i,ci+1);
       }
   }
  }
}
int main()
{
 cin>>p>>n>>s;
 bt(0,1);
 cout<<br<<endl;
 return 0;
}
