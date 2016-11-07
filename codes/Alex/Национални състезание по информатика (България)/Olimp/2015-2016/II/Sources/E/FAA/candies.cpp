#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long a,b,c,br=0,v;
    cin>>a>>b>>c;
    for(;a>10000 && b>20000 && c>10000;)
    {
        a=a-10000;br+=10000;
        b=b-10000;br+=10000;
        c=c-10000;br+=10000;
        b=b-10000;br+=10000;
    }
    for(;;)
    {
        a--;br++;
        if (b==0) break;
        b--;br++;
        if (c==0) break;
        c--;br++;
        if (b==0) break;
        b--;br++;
        if (a==0) break;
    }
    cout<<br<<endl;
    return 0;
}
