#include<iostream>
using namespace std;
int main (){
    int n;
cin>>n;
if(n==1){ cout<<1<<endl;
cout<<1<<" 1"<<endl;return 0;}
if(n==2){ cout<<1<<endl;
cout<<1<<" 1"<<endl;return 0;}
if(n==3){ cout<<2<<endl;
cout<<1<<" 1"<<endl;
cout<<1<<" 2"<<endl;return 0;}
if(n==4){ cout<<2<<endl;
cout<<2<<" 1 3"<<endl;
cout<<2<<" 2 3"<<endl;return 0;}
if(n==5){ cout<<3<<endl;
cout<<2<<" 3 5"<<endl;
cout<<4<<" 1 2 3 5"<<endl;
cout<<3<<" 2 4 5"<<endl;return 0;}
if(n==6){ cout<<3<<endl;
cout<<2<<" 3 5"<<endl;
cout<<4<<" 1 2 3 5"<<endl;
cout<<3<<" 2 4 5"<<endl;
return 0;}
if(n==7){ cout<<3<<endl;
cout<<3<<" 1 2 5"<<endl;
cout<<4<<" 1 2 4 6"<<endl;
cout<<3<<" 1 3 4"<<endl;
return 0;}
if(n==8){ cout<<3<<endl;
cout<<4<<" 1 2 5 8"<<endl;
cout<<4<<" 1 2 4 6"<<endl;
cout<<4<<" 1 3 4 8"<<endl;
return 0;}
if(n==9){ cout<<4<<endl;
cout<<4<<" 1 2 5 8"<<endl;
cout<<4<<" 1 2 4 6"<<endl;
cout<<4<<" 1 3 4 8"<<endl;
cout<<1<<" 9"<<endl;
return 0;}
if(n==10) {cout<<4<<endl;
cout<<4<<" 1 2 5 8"<<endl;
cout<<4<<" 1 2 4 6"<<endl;
cout<<5<<" 1 3 4 8 9"<<endl;
cout<<2<<" 9 10"<<endl;
return 0;
}
return 0;
}
