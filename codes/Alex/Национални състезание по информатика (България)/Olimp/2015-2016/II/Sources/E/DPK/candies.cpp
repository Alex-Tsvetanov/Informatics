#include <iostream>
using namespace std;
int main ()
{
    long long a,b,c,d,i=0,br=0;
    cin>>a>>b>>c;
    while (true)
    {
        i++;
        if (i%2==0)
        {if (c==0)break;
        else {c--;br++;}
        }
        else {if (a==0)break;
        else {a--;br++;}}
        if (b==0)break;
        else {b--;br++;}
        }
        cout<<br<<endl;
        return 0;
}
