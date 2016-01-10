#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int x=0;x<=n;x++){
        a[x]=0;
    }
    int m;
    cin>>m;
    int b,c;
    for(int x=0;x<m;x++){
        cin>>b>>c;
        a[b]=a[b]+1;
        a[c]=a[c]+1;
    }
    int k;
    cin>>k;
    int d=0;
    for(int x=0;x<=n;x++){
        if(a[x]>=k){
            d=d+1;
        }
    }
    cout<<d<<endl;
    for(int x=0;x<=n;x++){
        if(a[x]>=k){
            cout<<x<<" ";
        }
    }
}
