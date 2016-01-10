#include <iostream>
using namespace std;
int a[10000],otg[10000],br=0;
int main(){
int p,k;
cin>>p;
if(p<=10000){
    int m,buff;
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>buff;
        a[buff]++;
        cin>>buff;
        a[buff]++;
    }
    cin>>k;
    int last,q;
    for(int i=0;i<p;i++){
        if(a[i]>=k){
            otg[br++]=i;
        }
    }
    cout<<br<<endl;
    for(int i=0;i<br-1;i++){
        cout<<otg[i]<<" ";
    }
    cout<<otg[br-1]<<endl;
}
else cout<<"NEIN NEIN NEIN";
return 0;
}
