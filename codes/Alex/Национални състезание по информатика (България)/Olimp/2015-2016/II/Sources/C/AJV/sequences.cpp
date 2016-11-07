#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;
//queue<long long>Q;
long long k=0;
long long p,n,st,z[31][31];
long long nameri(long long o,long long s){
    long long j=0;
for(long long i=0;i<o and i<p and s<n;i++){
        if(z[o-i][s]==-1){
    z[o-i][s]=nameri(o-i,s+1);
            j=j+z[o-i][s];
//            cout<<j<<"tuuuuuuuuuk";
        }else{
        j=j+z[o-i][s];
        }
}
//cout<<j<<" za "<<o<<"\n";
if(j>1){
return j;
}else{
return 1;
}
}
int main(){
ios::sync_with_stdio(false);
cin>>p>>n>>st;
for(long long i=0;i<st and i<p;i++){
            for(long long i=0;i<31;i++){
for(long long r=0;r<31;r++){
    z[i][r]=-1;
}
}
    k=k+nameri(st-i,1);
//    cout<<"           "<<nameri(st-i,1);
}
cout<<k;
return 0;
}
