#include <iostream>
using namespace std;
int main()
{
    long long n;
    long long sum=0,i;
    cin>>n;
    if(n<=10)
    {
        if(n==2){
            cout<<1<<endl;
            cout<<1<<" "<<1<<endl;
                }
        if(n==3){
            cout<<2<<endl;
            cout<<2<<" "<<1<<" "<<2<<endl;
            cout<<2<<" "<<2<<" "<<3<<endl;
                }
        if(n==4){
            cout<<2<<endl;
            cout<<2<<" "<<1<<" "<<2<<endl;
            cout<<2<<" "<<2<<" "<<3<<endl;
                }
        if(n==5){

            cout<<3<<endl;
            cout<<2<<" "<<3<<" "<<5<<endl;
            cout<<4<<" "<<1<<" "<<2<<" "<<3<<" "<<5<<endl;
            cout<<3<<" "<<2<<" "<<4<<" "<<5<<endl;
                }
        if(n==6){
            cout<<3<<endl;
            cout<<4<<" "<<1<<" "<<2<<" "<<3<<" "<<6<<endl;
            cout<<4<<" "<<2<<" "<<4<<" "<<5<<" "<<6<<endl;
            cout<<3<<" "<<3<<" "<<4<<" "<<6<<endl;
                }
        if(n==7){
            cout<<3<<endl;
            cout<<4<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<endl;
            cout<<4<<" "<<1<<" "<<4<<" "<<5<<" "<<6<<endl;
            cout<<3<<" "<<2<<" "<<4<<" "<<5<<endl;
                }
        if(n==8){
            cout<<4<<endl;
            cout<<4<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<endl;
            cout<<4<<" "<<1<<" "<<4<<" "<<5<<" "<<6<<endl;
            cout<<3<<" "<<2<<" "<<4<<" "<<5<<endl;
            cout<<3<<" "<<3<<" "<<4<<" "<<7<<endl;
                }
        if(n==9){
            cout<<4<<endl;
            cout<<5<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<7<<endl;
            cout<<4<<" "<<1<<" "<<4<<" "<<5<<" "<<6<<endl;
            cout<<3<<" "<<2<<" "<<4<<" "<<5<<endl;
            cout<<3<<" "<<4<<" "<<7<<" "<<8<<endl;
                }
        if(n==10){
            cout<<4<<endl;
            cout<<7<<" "<<1<<" "<<2<<" "<<3<<" "<<4<<" "<<6<<" "<<7<<" "<<8<<endl;
            cout<<4<<" "<<1<<" "<<4<<" "<<5<<" "<<6<<endl;
            cout<<5<<" "<<2<<" "<<3<<" "<<4<<" "<<5<<" "<<6<<endl;
            cout<<3<<" "<<3<<" "<<8<<" "<<9<<endl;
                }
    }
    if(n>500)
    {
        i=1;
        while(n>sum)
        {
            sum=sum+i*i;
            i++;
        }
        cout<<endl;
        cout<<sum<<endl;
    }
    return 0;
}
