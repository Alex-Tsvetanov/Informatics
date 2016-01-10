#include <iostream>
#include <cstdio>
using namespace std;

    int stepen(int x){
        int j=2;
        for(int i=0;j<x;j++){
            j*=2;
        }
        return j;
    }

int main(){
    int n;
    scanf("%d",&n);
    if(n%2!=0)n--;
    if(n<8){
        printf("%d\n",n);
    }
    else{

        cout<<n*(n/10)+2*stepen(n/10)+(n%10)<<endl;
    }



}
