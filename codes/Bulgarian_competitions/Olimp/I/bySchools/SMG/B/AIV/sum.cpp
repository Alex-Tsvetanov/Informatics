#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n==1){
        cout<<1;
        return 0;
    }
    if(n==2){
        cout<<2;
        return 0;
    }

    int dvoiki=n/2;
    int chetvorki=n/4;
    int zasega=dvoiki*chetvorki;

    if(dvoiki%2==0){
        cout<<zasega+2;
        return 0;
    }else{
        cout<<zasega+chetvorki+2;
        return 0;
    }

    return 0;
}
