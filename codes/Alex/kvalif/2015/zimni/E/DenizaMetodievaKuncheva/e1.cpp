#include <iostream>
using namespace std;

int main()
{
    int x,y,d,a,b,m,n;
    cin>>x;
    cin>>y;
    cin>>d;
   a=((x*100+y)/2-d)/2;
   b=a+d;
   m=a%100;
   n=b%100;
   a=((a-a%100)/100);
   b=((b-b%100)/100);

    cout<<a<<" "<<m<<" "<<b<<" "<<n<<endl;

return 0;
}
