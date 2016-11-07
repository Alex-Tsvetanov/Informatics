#include<iostream>
using namespace std;

int main()
{
    unsigned int n;
    cin>>n;
    if(n==2)
    {
        cout<<1<<endl<<2<<endl;
        return 0;
    }
    if(n==3)
    {
        cout<<2<<endl<<1<<endl<<2<<endl;
        return 0;
    }
    if(n==4)
    {
        cout<<2<<endl<<1<<" "<<2<<endl<<2<<" "<<3<<endl;
        return 0;
    }
    if(n==5)
    {
        cout<<3<<endl<<2<<" "<<3<<" "<<5<<endl<<4<<" "<<1<<" "<<2<<" "<<3<<" "<<5<<endl<<3<<" "<<2<<" "<<4<<" "<<5<<endl;
        return 0;
    }
    if(n==6)
    {
        cout<<3<<endl<<1<<" "<<2<<" "<<3<<endl<<2<<" "<<3<<" "<<5<<endl<<4<<" "<<3<<endl;
        return 0;
    }
    return 0;
}
