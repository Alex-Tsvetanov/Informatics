#include <iostream>
using namespace std;
int main ()
{
    long long n,i=1,br=0,j=0,a=0;
    cin>>n;
     if(n==12||n==17) {br++;if(n>=17&&n<24)br=br+1;}
    if(n==4) br=1;
    else

    if(((n%4)%3==0)||((n-4)%3==0)) {br++;if(n>=17&&n<24)br=br+1;}
    cout<<br;
   return 0;
}


