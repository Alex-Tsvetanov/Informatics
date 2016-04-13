#include <iostream>
using namespace std;
int main ()
{
    long long n,br=0;
    cin>>n;
    if(n<=0||n>1000000)return -1;
    if(n<4)cout<<"0"<<endl;
    if(n==4)cout<<"1"<<endl;
    if(n<7)
    {
        if(n%4!=0)cout<<"0"<<endl;
    }
    else
    {
        for(int a=4,b=3,l=3; l!=0; a+=3,b+=2,l--)
        {
            if((n-a)%b==0)br++;
        }
        cout<<br<<endl;
    }

    return 0;
}

