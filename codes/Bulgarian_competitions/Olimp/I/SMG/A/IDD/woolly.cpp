#include <iostream>
#include <string.h>
using namespace std;
int n,m;
char a[72], b[72], res[72], pr;
int main(){
    cin>>a>>b;
    n=strlen(a);
    m=strlen(b);
    for (int i=0; i<n/2; ++i){
        swap(a[i],a[n-i-1]);
    }
    for (int i=0; i<m/2; ++i){
        swap(b[i],b[m-i-1]);
    }
    if (n>m){
        swap(n,m);
        swap(a,b);
    }
    for (int i=n; i<m; ++i){
        a[i]='0';
    }
    n=m;
    pr='0';
    for (int i=0;i<n;++i){
        int cur=0;
        int q=0;
        cur = (pr=='1') + (a[i]=='1') + (b[i]=='1');
        q = (pr=='?') + (a[i]=='?') + (b[i]=='?');
        if (q>0){res[i]='?';}
        else{res[i]='0'+cur%2;}
        if (q>0 && q+cur>1){pr='?';}
        else if (q==0 && cur>1){pr='1';}
        else{pr='0';}
    }
    if (pr!='0'){res[n]=pr;++n;}
    for (int i=n-1; i>=0; --i){
        cout<<res[i];
    }
    cout<<endl;
    return 0;
}
