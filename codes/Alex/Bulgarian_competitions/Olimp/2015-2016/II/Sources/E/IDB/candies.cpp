#include <iostream>
using namespace std;
int main ()
{
    long long a,b,c,br=0;
    cin>>a>>b>>c;
    if(a+b+c<=0||a+b+c>2*1000000000)return -1;
    while(a!=0||b!=0||c!=0)
    {
        if(a!=0)
        {
            a--;
            br++;
        }
        else
        {
            cout<<br<<endl;
            break;
        }
        if(b!=0)
        {
            b--;
            br++;
        }
        else
        {
            cout<<br<<endl;
            break;
        }
        if(c!=0)
        {
            c--;
            br++;
        }
        else
        {
            cout<<br<<endl;
            break;
        }
        if(b!=0)
        {
            b--;
            br++;
        }
        else
        {
            cout<<br<<endl;
            break;
        }
    }

    return 0;
}

