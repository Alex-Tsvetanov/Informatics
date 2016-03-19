#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int a,b,c,i;
    int br=0;
    cin>>a>>b>>c;
    while((a>0)&&(b>0)&&(c>0))
    {
        if(a>0)
        {
            a=a-1;
            br++;
        }
        if(b>0)
        {
            b=b-1;
            br++;
        }
        if(c>0)
        {
            c=c-1;
            br++;
        }
        if(b>0)
        {
            b=b-1;
            br++;
        }
    }
    cout<<br;
}

