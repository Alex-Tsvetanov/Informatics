#include <iostream>
int main (){
    int a,b,c=0;
    cin>>b;
    int cifri[100];
    while(b>0){
        cifri[i]=b%10;
        b=b-b%10;
        i++;
            }
    sort(cifri; cifri+4);
    for(p=0;p<i;p++){
    c=cifri[p]*10+cifri[p+1];
    }
    for(t=i;t>0;t--){
    b=cifri[t]*10+cifri[t-1];
    }
    cout<<c-b;
    return 0;
}

