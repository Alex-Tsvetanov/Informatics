#include<iostream>
using namespace std;
int main(){
long long brsguv=0,m,n;
cin>>m>>n;
if(m==1 or n==1){
    if(m==1){
        brsguv=n-1;
    }
    if(n==1){
        brsguv=m-1;
    }
}else{
    while(m!=1){
        m=m/2+m%2;
        brsguv++;

    }
    while(n!=1){
        n=n/2+n%2;
        brsguv++;

    }



}
cout<<brsguv<<endl;
return 0;
}
