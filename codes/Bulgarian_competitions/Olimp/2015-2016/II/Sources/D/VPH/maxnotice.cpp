#include <iostream>
using namespace std;
long long pole[100][100];
long long l,h,x,y,t,z,g=100,g1=0,alfa=0,w=0;
void sased(long long x,long long y,long long t,long long z){
    cout<<x<<" "<<y<<" "<<z<<" "<<t<<endl;
    if(w==0){
    g=100;
    g1=0;
    if(alfa<z*t){alfa=z*t;}
    if(x+t<l && t<g+1 && pole[x+t][y]==0){sased(x, y, t+1, z);}else{if(t>g1-1){ g=t;g1=t;
    if(y+z<h && pole[x+1][y+z]==0){sased(x, y, 1, z+1);}}else{w=1;}}
}}
int main(){
long long n,i,r,o;
cin>>l>>h>>n;
for(o=0; o<h; o++){
    for(i=0; i<l; i++){
        pole[i][o]=0;
    }
}
for(i=0; i<n; i++){
    cin>>x>>y>>t>>z;
    for(o=x;o<x+t; o++){
        for(r=y;r<y+z; r++){
            pole[o][r]=1;
        }
    }
}
for(i=0; i<l; i++){
    for(o=0; o<h; o++){
        if(pole[i][o]==0){
            sased(i, o, 1, 1);
            g=100;
            w=0;
        }
    }
}
cout<<alfa;
return 0;
}
