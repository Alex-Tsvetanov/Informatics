#include<iostream>
using namespace std;
int main (){
    long long i,j,len,br2=0,br=0,t=0;
    char a[10000];
    cin>>len>>a;
    if(len%2==0){
        for(i=0; i<len/2-1; i++){
            for(j=len/2; j<len; j++){
                if(a[i]==a[j]){
                    br2++;
                }
            }
        }
    }else{
        br2=1;
        for(i=0; i<len/2-1; i++){
            for(j=len/2+1; j<len; j++){
                if(a[i]==a[j]){
                    br2++;
                }
            }
        }
    }
    if(2*br2>=len){
       cout<<0;
    }else{
         for(i=0; i<len-1; i++){
        if(a[len-1]==a[i]){
            br++;
        }
    }
    if(br==0){
        cout<<len-1<<endl;
        for(i=len-2; i>=0; i--){
            cout<<a[i];
        }

    }else{
        for(i=0; i<len-1; i++){
            if(a[len-1]==a[i]){
                t=i;
                break;
            }
        }
        cout<<i<<endl;
        for(i=0; i<t; i++){
            cout<<a[i];
        }

    }
    }
    cout<<endl;
return 0;
}
