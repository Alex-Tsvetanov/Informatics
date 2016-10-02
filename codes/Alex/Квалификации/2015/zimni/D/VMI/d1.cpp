#include<iostream>
using namespace std;

int main(){
        long long n,T[10],i=0;
        cin>>T[0]>>T[1]>>T[2]>>n;
        int d=0;

   for(i=0;i<3;i++){
        if(T[i]<3){
            if(T[i]==1){
                d+=1+0+0;

            }
            if(T[i]==2){
                d+=1+1+0;
            }
        }else{
            d+=(T[i]-1)+(T[i]-2)+(T[i]-3);
        }
    }

        cout<<d<<endl;
    return 0;
}
