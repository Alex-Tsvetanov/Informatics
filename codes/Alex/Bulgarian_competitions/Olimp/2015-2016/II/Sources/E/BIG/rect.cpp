#include<iostream>
using namespace std;
int main(){
    long long n,a,b,broi=0;
    cin>>n;
    while(n>1000000){
        cin>>n;
    }
    for(b=1;b<n;b++){
        for(a=1;a<=b;a++){
            if(a*(b+1)+b*(a+1)==n){
                broi++;
            }
        }
    }
    cout<<broi;
return 0;
}
