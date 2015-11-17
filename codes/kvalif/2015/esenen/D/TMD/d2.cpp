#include<iostream>
using namespace std;
int main(){
char a[3],m[3],q;
bool pole[26][26];
int c,k,b,n,i,i2;
cin>>a;
b=a[0]-'a';
cin>>m;
n=m[0]-'a';
if(a[2]<='9' and a[2]>='0'){
c=(a[1]-'0')*10+(a[2]-'0')-1;
}else{
c=a[1]-'0'-1;
}
if(m[2]<='9' and m[2]>='0'){
k=(m[1]-'0')*10+(m[2]-'0')-1;
}else{
k=m[1]-'0'-1;
}
for(i=0;i<26;i++){
for(i2=0;i2<26;i2++){
pole[i][i2]=0;
}
}
pole[k-1][n-2]=1;
pole[k-1][n+2]=1;
pole[k+1][n-2]=1;
pole[k+1][n+2]=1;
pole[k-2][n-1]=1;
pole[k-2][n+1]=1;
pole[k+2][n-1]=1;
pole[k+2][n+1]=1;
for(i=0;i<b+1;i++){
q='a'+i;
cout<<q;
}
cout<<endl;
for(i=0;i<c;i++){
cout<<i+1;
for(i2=0;i2<b+1;i2++){
if(i==k and i2==n){
cout<<"H";
}else{
if(pole[i][i2]==0){
cout<<"O";
}else{
cout<<"X";
}
}
}
cout<<endl;
}
return 0;
}
