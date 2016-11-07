#include <iostream>
using namespace std;
int main()
{
int N;
cin>>N;
if(N%2)cout<<0<<endl;
if(N==2)cout<<0<<endl;
if(N%4 && N/2 && N-2>0)cout<<1<<endl;
if(N==0)cout<<0<<endl;
if(N/4 && N-8>=0 && N-16>0 && N-32>0)cout<<2<<endl;
if(N/8 && N%16)cout<<2<<endl;
if(N==4)cout<<1<<endl;
if(N/16 && N-16>0 && N-32>0)cout<<8<<endl;
if(N==16)cout<<4<<endl;
if(N/32)cout<<16<<endl;
return 0;
}
