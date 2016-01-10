#include<iostream>
#include<vector>
using namespace std;

long long minn=9999999,maxx=0;
long long brmin=0;
long long brmax=0;
long long sbor1=0;
long long sbor2=0;
//long long min1,max1;
long long a[20000];
//long long minP[20000],maxP[20000];
long long Lmax=0,Lmin=0,Rmax=0,Rmin=0;

int main(){

long long n;
cin>>n;

for(long long i=0;i<n;i++){
    cin>>a[i];
}



for(long long i=0;i<n;i++){
    if(a[i]<minn){
        minn=a[i];
    }

}

for(long long i=0;i<n;i++){
    if(a[i]>maxx){
        maxx=a[i];
    }
}



for(long long i=0;i<n;i++){
    if(a[i]==minn){
        Lmin=i;
        break;
    }
}
for(long long i=0;i<n;i++){
    if(a[i]==maxx){
        Lmax=i;
        break;
    }
}
for(int i=n-1;i>=0;i--){
    if(a[i]==minn){
        Rmin=i;
        break;
    }
}
for(int i=n-1;i>=0;i--){
    if(a[i]==maxx){
        Rmax=i;
        break;
    }
}

if(Rmax-Lmin>Rmin-Lmax){
    cout<<Lmin+1<<" "<<Rmax+1<<endl;
}
if(Rmax-Lmin<Rmin-Lmax){
    cout<<Lmax+1<<" "<<Rmin+1<<endl;
}
if(Rmax-Lmin==Rmin-Lmax){

        for(int i=Lmax;i<=Rmin;i++){
            sbor1=sbor1+a[i];
        }
        for(int i=Lmin;i<=Rmax;i++){
            sbor2=sbor2+a[i];
        }
        if(sbor1 < sbor2){
            cout<<Lmax+1<<" "<<Rmin+1<<endl;
        }
        else{
            cout<<Lmin+1<<" "<<Rmax+1<<endl;
        }
}

return 0;
}
