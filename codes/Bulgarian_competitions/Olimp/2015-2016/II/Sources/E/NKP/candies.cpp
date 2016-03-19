#include <iostream>
using namespace std;
int main()
{
   long long a,b,c,min=33,br=0,sb1=0,sb2=0,sb3=0,izr,izr1,izr2;
   cin>>a>>b>>c;
   min=a;
   if(min>b)min=b;
   if(min>c)min=c;
   sb1=a;
   sb2=b;
   sb3=c;
   izr=(min-1)*3+1;
   izr1=(min-1)*3+2;
   izr2=(min-1)*3+3;
   if(a==b&&a==c&&b==c)cout<<izr<<endl;
   if(min==a&&b!=a&&c!=a&&c!=b)cout<<izr<<endl;
   if(min==b&&a!=b&&b!=c&&a!=c)cout<<izr1<<endl;
   if(min==c&&a!=c&&b!=c&&a!=b)cout<<izr2<<endl;
   if(min==a&&b==min&&c!=a)cout<<izr<<endl;
   if(min==a&&c==min&&a!=b)cout<<izr<<endl;
   if(min==b&&b==c&&min!=a)cout<<izr1<<endl;
   if(min==b&&b!=c&&b!=a&&a==c)cout<<izr1<<endl;
   if(min==a&&b==c&&a!=b&&a!=c)cout<<izr<<endl;
   if(min==c&&a==b&&a!=c&&b!=c)cout<<izr2<<endl;
   return 0;
}
