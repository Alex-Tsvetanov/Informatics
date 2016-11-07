#include <iostream>
using namespace std;
int main () {
long long N;
cin>>N;
if(N<4){
cout<<0;
}
if(N==4){
cout<<"1";
}
if((N-4)/3==1 or (N-4)/3==2 or (N-4)/3==3 or (N-4)/3==4 or (N-4)/3==5 or (N-4)/3==6 or (N-4)/3==7 or (N-4)/3==8 or (N-4)/3==9){
cout<<1;
}
if(N==10 or N==13 or N==16 or N==10 or N==19 or N==22 or N==25){
cout<<"2";
}

return 0;}
