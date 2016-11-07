#include <iostream>

using namespace std;

int main( )
{

long long a,b,c,br=3,i=1;

cin>>a>>b>>c;

if( a==0 || b==0 || c==0 )cout<<0<<endl;

else

{

a=a-1;b=b-1;c=c-1;

while( b>0 )
{
 if( i%2==0 )

 {
     a=a-1;b=b-1;br=br+1+1;
 }
 if( i%2!=0 && i>1 )

 {
     b=b-1;c=c-1;br=br+1+1;
 }

 i++;

}

  cout<<br<<endl;

}

return 0;
}
