#include<iostream>
using namespace std;
int main(){
    int n, i, j, dwe[]={0,0}, bd[]={0,0}, len;
    cin>>n;
    char vhod[n+1], vn;
    cin>>vhod;
    bool minato=false;
    vn=0;
    vhod[n]=0;
    for(i=n-1;i>=n/2;i--){
        dwe[0]=i;
        dwe[1]=0;
        for(j=1;j<n-i+1;j++){
            if(vhod[i-j]==vhod[i+j]){
                dwe[1]++;
            }
        }
        if(dwe[1]>bd[1] or i==n){
            bd[1]=dwe[1];
            bd[0]=dwe[0];
        }
    }
    len=n-bd[1]+1;
    if(len*2-1==n or len*2==n){
        cout<<0<<endl;
        return 0;
    }
    cout<<len<<endl;
    for(i=bd[0]-1, j=1;i-j>=0;j++){
        if(vhod[i+j]==vn)minato=true;
        if(minato)cout<<vhod[i-j];
    }
    cout<<endl;
    return 0;
}
