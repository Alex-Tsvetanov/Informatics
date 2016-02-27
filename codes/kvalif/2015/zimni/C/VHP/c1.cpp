#include<iostream>
#include<math.h>
using namespace std;
int main(){

    long long n,vhod;
    long long foundNumber[100];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>vhod;
        if(vhod==1){
            foundNumber[i]=1;
        }else{
            foundNumber[i]=2;
        }
        for(long long delitel=2;delitel<=sqrt(vhod);delitel++){
            if(vhod%delitel==0){
                if(delitel!=sqrt(vhod)){
                    foundNumber[i]++;
                }
                foundNumber[i]++;
                if(n==1){
                    cout<<delitel<<"  ";
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<foundNumber[i]<<" ";
    }
    cout<<endl;


return 0;
}
