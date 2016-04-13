#include<iostream>
using namespace std;
long long f(long long num){
    long long i,answ=0;
    for(i=1;i<=num;i++){
       if(num % i == 0){
         answ++;
       }
    }
    return answ;
}
int main(){
long long n,answ[101],i,number;
cin>>n;
for(i=0;i<n;i++){
     cin>>number;
     answ[i] = f(number);
}
for(i=0;i<n;i++){
     cout<<answ[i]<<" ";
}
cout<<endl;
return 0;
}
