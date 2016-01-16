#include<iostream>
#include<cstring>
using namespace std;
bool prostolie=true;
char a[3006];
long long prosti4isla[3006],k=1,chislo=0;
int main(){
    cin>>a;
   // cout<<strlen(a)<<" ";
    prosti4isla[0]=2;
    for(long long i=3;i<100006;i=i+2){
            prostolie=true;
        for(long long r=3;r<=i/r;r=r+2){
            if(i%r==0){
                    prostolie=false;
                   break;
            }
        }
      //  if(i==9){
           // cout<<prostolie<<"\n";
       // }
            if(prostolie==true){
                    if(k==strlen(a)+1){
                        break;
                    }
             prosti4isla[k]=i;
             k++;
            }
    }
    for(long long i=0;i<strlen(a);i++){
        chislo=chislo+prosti4isla[i]*(a[i]-'0');
      // cout<<prosti4isla[i]<<"\n";
    }
    cout<<chislo<<"\n";
return 0;
}
