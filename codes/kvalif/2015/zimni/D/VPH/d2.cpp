#include<iostream>
using namespace std;
char h[1051],p[1051];
int main(){
long long n,m=0,l=0;
cin>>n>>p;
for(int i=0; i<n; i++){
    if(p[n-1] != p[i] && l==0){
        for(int o=m; m>0 && o>-1; o--){
            h[o+1]=h[o];
        }
        h[0]=p[i];
        m++;
    }else{l=1;}
}
cout<<m<<endl<<h<<endl;
return 0;
}
