#include <iostream>
#include <cctype>
using namespace std;
int main ()
{
    int b,i=0,a=0,br=0,c;
    char x='1',y='2',z;
    while (true)
    {
        c=y;
        y=x;
        cin.get(x);
        if (c==y && x=='.')
        {
        while (i!=0)
        {
            a++;
            i=i/10;
        }
        i=0;
        }
        if (x=='.')break;
        br++;
        if(y==x)
        {
            i++;
        }
        if(y!=x)
        {
        while (i!=0)
        {
            a++;
            i=i/10;
        }
        a++;i=0;
        }
    }
    cout<<br-a<<endl;
    return 0;
}
