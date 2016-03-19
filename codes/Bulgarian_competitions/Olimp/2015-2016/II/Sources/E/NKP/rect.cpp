#include <iostream>
using namespace std;
int main()
{
    long long a,b,br=0,gum;
    cin>>a;
    for(int i=a/2;i!=0;i--)
    {
        b=(a/2)/i;
        if(a%2==1)b=a/i;
        gum=b*(i+1)+i*(b+1);
        if(b==1)
        {
            gum=i*b*2+(i*b)/2+2;
        }
        if(b==i)
        {
            if(i*b*3==a)br++;
        }
        else
        {
        if(gum==a)br++;
        }
    }
    cout<<br<<endl;
    return 0;
}
