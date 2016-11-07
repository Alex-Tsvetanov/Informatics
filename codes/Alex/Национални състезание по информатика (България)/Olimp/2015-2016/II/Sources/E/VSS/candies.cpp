#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;
int main()
{


    unsigned long long int a,b,c,m,br=0;
    cin>>a>>b>>c;

    do
    {

        m=a;a=a-1;br++;if(m==0)break;
        m=b;b=b-1;br++;if(m==0)break;
        m=c;c=c-1;br++;if(m==0)break;
        m=b;b=b-1;br++;if(m==0)break;

    }
    while(m!=0);


    cout<<br-1<<endl;

    return 0;
}
