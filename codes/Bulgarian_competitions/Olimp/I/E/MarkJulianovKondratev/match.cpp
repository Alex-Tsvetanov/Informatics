#include<iostream>
using namespace std ;
 int  main ()
{
  long long a,b,c,d;
  cin>>a;
  cin>>b;
  cin>>c;
  cin>>d;
   if(a==c or b==d or b==c or a==d){
    cout<<"Yes";
    cout<<a*b;
   }else{
    cout<<"No"<<endl;
    cout<<a+b+c+d;
   }
    return 0 ;
}
