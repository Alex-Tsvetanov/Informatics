#include<iostream>
#include<cmath>
using namespace std;
int a[20010];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, sI, bI, lastSI=-1, lastBI=-1, resLen=0;
    cin>>n>>a[0];
    sI=0;
    bI=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]>a[bI]) bI=i;
        if(a[i]<a[sI]) sI=i;
    }
    for(int i=n-1;i>=0&&(lastSI==-1||lastBI==-1);i--){
        if(lastSI==-1&&a[sI]==a[i]) lastSI=i;
        if(lastBI==-1&&a[bI]==a[i]) lastBI=i;
    }
    sI++;
    lastSI++;
    bI++;
    lastBI++;
    if(lastSI-bI<lastBI-sI){
        cout<<sI<<" "<<lastBI<<"\n";
        return 0;
    }
    if(lastSI-bI>lastBI-sI){
        cout<<bI<<" "<<lastSI<<"\n";
        return 0;
    }
    if(sI<bI){
        cout<<sI<<" "<<lastBI<<"\n";
        return 0;
    }
    cout<<bI<<" "<<lastBI<<"\n";
    return 0;
}
