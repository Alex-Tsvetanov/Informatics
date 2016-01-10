#include<iostream>
using namespace std;
int main(){
long long o=0, m, n;
cin>>m>>n;
while(m>1 || n>1){
    o++;
    if(m>1){
       if(m==2){m--;}
       m=(m+1)/2;
    }else{
        if(n>1){
            if(n==2){n--;}
            n=(n+1)/2;
        }
    }
}
cout<<o;
return 0;
}
