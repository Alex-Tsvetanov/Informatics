#include<iostream>
using namespace std;
int main (){
long long N,S,P,a,b,delitel,x,i,j=0;
cin>>N;
delitel=N/2;
       if(N%2==0){
              x=N/2+2;
              for(i=delitel-1; i>1; i--){
                     if(N%i==0){
                            if(N/i+i<x){
                                   x=N/i+i;
                            }
                     }
              }
       }else{
              for(i=2; i<N; i++){
                     if(N%i==0){
                            j++;
                     }
              }
              if(j!=0){
                     delitel=delitel-(((((delitel%10)*10)%10)/10));
                     for(i=delitel-1; i>1; i--){
                            if(N%i==0){
                                   if(N/i+i<x){
                                          x=N/i+i;
                                   }
                            }
                     }
              }else{
                     x=N+1;
              }
       }
cout<<x*2;
return 0;
}
