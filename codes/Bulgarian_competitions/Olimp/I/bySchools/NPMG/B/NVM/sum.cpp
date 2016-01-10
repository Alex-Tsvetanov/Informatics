#include<iostream>
using namespace std;

int main(){
int N;
cin>>N;
if(N<1 || N>3000){
    cout<<"greshka";
}
for(int i = 2; i<=N; i+=2){
   if(i==N || i+1 == N){
    cout<<i;
    break;
   }
}
return 0;

}
