#include<iostream>
using namespace std;
int main(){

int n1,n2,n3;
cin>>n1>>n2>>n3;
if(n1==1 && n2==1 && n3==1)cout<<"3";
else if(n1==2 && n2==2 && n3==2)cout<<6;
else cout<<(n1-1)+(n2-1)+(n3-1)+1;

return 0;
}
