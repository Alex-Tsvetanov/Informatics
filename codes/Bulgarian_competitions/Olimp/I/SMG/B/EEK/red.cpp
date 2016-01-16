#include<iostream>
using namespace std;
int main(){
int n;
cin>>n;
int a[n];
for(int x=0;x<n;x++){
    cin>>a[x];
}
int s,r;
int d,c;
r=a[0]-a[1];
s=a[0]+a[1];
d=0;
c=1;
for(int x=0;x<n;x++){
    for(int y=x+1;y<n;y++){
        if(a[x]-a[y]>r){
                r=a[x]-a[y];
                s=a[x]+a[y];
                d=x;
                c=y;
        }
        if(a[y]-a[x]>r){
                r=a[y]-a[x];
                s=a[x]+a[y];
                d=x;
                c=y;
        }
        if(a[x]-a[y]==r){
            if(s>a[x]+a[y]){
                s=a[x]+a[y];
                d=x;
                c=y;
            }
        }
        if(a[y]-a[x]==r){
            if(s>a[x]+a[y]){
                s=a[x]+a[y];
                d=x;
                c=y;
            }
        }
    }
}
cout<<d+1<<" "<<c+1;
}
