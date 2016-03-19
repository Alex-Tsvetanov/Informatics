#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    long long a,b,c,br=0,i;
    cin>>a>>b>>c;
    br++;
    for (i=0;br<=a+b+c;i++)
    {
    if(b==0){break;}
    br++;b--;
    if(c==0){break;}
    br++;c--;
    if(b==0){break;}
    br++;b--;
    if(a==0){break;}
    br++;a--;
    
    }
    cout<<br<<endl;
    return 0;
}