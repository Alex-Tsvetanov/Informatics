#include<iostream>
using namespace std;
long long n,m;
char pole[103][103];
long long k=0,suma=0;
bool a;
int main(){
cin>>n>>m;
for(long long i=0;i<n;i++){
cin>>pole[i];
}
for(long long i=0;i<n;i++){
a=true;
for(long long r=0;r<m;r++){
if(pole[i][r]=='.'){
a=false;
}
}
if(a==true){
k++;
}else{
suma=suma+(k*(k+1))/2;
k=0;
}
}
suma=suma+(k*(k+1))/2;
cout<<suma;
cout<<"\n";
return 0;
}
