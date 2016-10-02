#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;
long long n,m,a,br=0,da=1,db=1,sborove[1000],sborove2[1000],pokolkopyti[1000],pokolkopyti2[1000],deliteli[100000],zadelitel[100000],k=0,dokyde=0,p=0;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    //n=100;m=100;
    for(long long i=0;i<n;i++){
        for(long long r=0;r<m;r++){
            cin>>a;
         // a=1000000;
sborove[i]=sborove[i]+a;
sborove[r+n]=sborove[r+n]+a;
        }
    }
    for(long long i=0;i<n+m;i++){
        if(sborove[i]<0){
            sborove[i]=sborove[i]*(-1);
        }
    }
    a=0;
    sort(sborove+0,sborove+n+m);
p=0;
while(sborove[p]==0){
    p++;
}
dokyde=sborove[p];
for(long long i=0;i<n+m;i++){
        if(sborove[i]!=0){
                //cout<<"tuk";
             //   cout<<sborove[i];
    for(long long r=2;r<=dokyde and r<=sborove[i];r++){
           // cout<<a;
            if(a==0){
                zadelitel[r]=99999999999999;
            }
        k=0;
            while(sborove[i]%r==0){
                k++;
    sborove[i]=sborove[i]/r;
            }
          //  cout<<"Za "<<i<<" pri r = "<<r<<"ima go "<<k<<" pyti";
            if(k<zadelitel[r]){
                zadelitel[r]=k;
            }
            if(i==n+m-1){
                    for(long long f=0;f<zadelitel[r];f++){
                da=da*r;
                    }
            }
    }
    a=1;
        }
}
    cin>>n>>m;
  // n=100;m=100;
    for(long long i=0;i<n;i++){
        for(long long r=0;r<m;r++){
            cin>>a;
  //a=1000000;
sborove2[i]=sborove2[i]+a;
sborove2[r+n]=sborove2[r+n]+a;
        }
    }
        for(long long i=0;i<n+m;i++){
        if(sborove2[i]<0){
            sborove2[i]=sborove2[i]*(-1);
        }
    }
    sort(sborove2+0,sborove2+n+m);
    p=0;
while(sborove2[p]==0){
    p++;
}
dokyde=sborove2[p];
    a=0;
for(long long i=0;i<n+m;i++){
                if(sborove2[i]!=0){
    for(long long r=2;r<=dokyde and r<=sborove2[i];r++){
            if(a==0){
                zadelitel[r]=99999999999999;
            }
        k=0;
            while(sborove2[i]%r==0){
                k++;
    sborove2[i]=sborove2[i]/r;
            }
          //  cout<<"Za "<<i<<" pri r = "<<r<<"ima go "<<k<<" pyti";
            if(k<zadelitel[r]){
                zadelitel[r]=k;
            }
            if(i==n+m-1){
                    for(long long f=0;f<zadelitel[r];f++){
                db=db*r;
                    }
            }
    }
    a=1;
                }
}
cout<<da<<" "<<db;
if(da%db==0 or db%da==0){
cout<<"\nY\n";
}else{
cout<<"\nN\n";
}
return 0;
}
