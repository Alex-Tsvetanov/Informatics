#include <iostream>
using namespace std;
int main()
{
long long a, b, c;
cin>>a>>b>>c;
if((a==0&&b!=0&&c!=0)||(a==0&&b==0&&c!=0)||(a==0&&b!=0&&c==0)) cout<<"0"<<endl;
else
if((b==0&&a!=0&&c!=0)||(b==0&&c==0&&a!=0)) cout<<"1"<<endl;
else
if(c==0&&a!=0&&b!=0) cout<<"2"<<endl;
else
if((a>b&&c>b)||(a==b&&c>b)||(c==b&&a>b)||(a==b&&b==c)||(a*2>b&&c*2>b)) cout<<b*2+1<<endl;
else
if(a*2<b&&c*2<b&&a<c) cout<<3+a*3<<endl;
else
if(a*2<b&&c*2<b&&c<a) cout<<4+c*3<<endl;
else
return 0;
}
