#include <iostream>
using namespace std;
int main()
{
    long long n,a,b,c,d,br=0;
    cin>>n;
    for(a=1;a<=n;a++)
    {
      for(b=1;b<=n;b++)
        {
            if(b>=a)
            {
                c=(a-1)*b;
                d=(b-1)*a;
                if((a*2+b*2+c+d)==n)br++;
            }
        }
    }
    cout<<br<<endl;

    return 0;
}
