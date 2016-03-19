#include<iostream>
#include<cmath>
using namespace std;
int main(){
long long n,i,maks,j,minn,pozg,pozm,daljina;
cin>>n;
long long a[n];
for(i=0;i<n;i++){
cin>>a[i];
}
pozm=0;
pozg=0;
maks=a[0];
minn=a[0];
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
        if(a[j]>=maks){
            maks=a[j];
            pozg=j;
        }
        if(a[j]<=minn){
            minn=a[j];
            pozm=j;

        }
    }
}
daljina=0;
daljina=abs(pozg-pozm);
/*
for(i=0;i<n;i++){
cout<<a[i];
}
cout<<endl<<maks<<endl<<minn<<endl<<daljina;
*/

cout<<pozm<<" "<<pozg;
return 0;
}
