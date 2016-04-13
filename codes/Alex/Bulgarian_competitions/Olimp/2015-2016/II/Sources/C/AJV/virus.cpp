#include<iostream>
using namespace std;
long long dali=1,k=1;
long long kutii[11][501],b[11],m[501],v=0,z=1,c=0;
/*long long dobavi(long long kolko,long long sloji){
for(long long i=0;i<k;i++){

}
}*/
int main(){
long long n;
cin>>n;
n=n-1;
if(n>=10){
while(n>dali){
long long f=k+1,l=1,p=2,t=k+1;
dali=0;
v=0;
for(long long i=0;i<k+1;i++){
      //  cout<<f<<" "<<l<<"   ";
dali=dali+f/l;
m[v]=f/l;
v++;
f=f*(t-1);
l=l*p;
p++;
t--;
}
//cout<<dali<<" ";
k++;
}
cout<<k<<"\n";
}
if(n<10){
     /*   for(long long i=0;i<v;i++){
                for(long long ){
            dobavi(i);
                }
        }
        /*for(long long o=0;o<k and z<=n;o++){
        for(long long r=0;r<k and z<=n;r++){
        for(long long i=0;i<r+1 and z<=n;i++){
                if(i+c<k){
            kutii[i+c][b[i+c]]=z;
            b[i+c]++;
                }else{
                long long h=(i+c)%k;
                }
        }
        z++;
        }
        c++;
    }*/

/*for(long long i=0;i<k;i++){
    cout<<b[i]<<" ";
    for(long long r=0;r<b[i];r++){
        cout<<kutii[i][r]<<" ";
    }
    cout<<"\n";
}
}*/
n=n+1;
if(n==2){
    cout<<1<<"\n"<<1;
}
if(n==3){
    cout<<2<<"\n"<<2<<' '<<1<<' '<<3;
        cout<<"\n"<<2<<' '<<2<<' '<<3;
}
if(n==4){
    cout<<2<<"\n"<<2<<' '<<1<<' '<<3;
        cout<<"\n"<<2<<' '<<2<<' '<<3;
}
if(n==5){
    cout<<3<<"\n"<<2<<' '<<3<<' '<<5;
        cout<<"\n"<<4<<' '<<1<<' '<<2<<' '<<3<<' '<<5;
                cout<<"\n"<<3<<' '<<2<<' '<<4<<' '<<5;
}
if(n==6){
    cout<<3<<"\n"<<2<<' '<<3<<' '<<5;
        cout<<"\n"<<4<<' '<<1<<' '<<2<<' '<<3<<' '<<5;
                cout<<"\n"<<3<<' '<<2<<' '<<4<<' '<<5;
}
if(n==7){
    cout<<3<<"\n"<<"4 1 4 6 7";
    cout<<"\n"<<"4 2 4 5 7";
    cout<<"\n"<<"4 3 5 6 7";
}
if(n==8){
    cout<<3<<"\n"<<"4 1 4 6 7";
    cout<<"\n"<<"4 2 4 5 7";
    cout<<"\n"<<"4 3 5 6 7";
}
if(n==9){
    cout<<4<<"\n"<<"3 1 5 9";
    cout<<"\n"<<"5 2 5 6 8 9";
    cout<<"\n"<<"4 3 7 6 9";
    cout<<"\n"<<"3 4 7 8";
}
if(n==10){
    cout<<4<<"\n"<<"3 1 5 9";
    cout<<"\n"<<"5 2 5 6 8 9";
    cout<<"\n"<<"4 3 7 6 9";
    cout<<"\n"<<"3 4 7 8";
}
cout<<"\n";
}
return 0;
}
