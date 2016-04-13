#include<iostream>
using namespace std;
bool a[100][100];
int main(){
int i,j,k,l,s,maxs=0,p,q,r,m,n,t,x,y,suobsht,o,b,c,d;
cin>>m>>n>>suobsht;
for(i=0;i<suobsht;i++){
cin>>o>>b>>c>>d;
for(j=b;j<b+d;j++){
for(k=o;k<o+c;k++){
a[j][k]=true;
}
}
}
for(i=0;i<n;i++){
for(j=0;j<m;j++){
k=i;l=j;y=m;
while(k<n and a[k][l]!=1){
l=j;
while(l<y and a[k][l]!=1){
l++;
}
y=l;
k++;
s=(k-i)*(y-j);
if(maxs<s){
maxs=s;
//cout<<i<<" "<<j<<" "<<k<<" "<<y<<endl;
}
}
}
}
cout<<maxs<<endl;
return 0;
}
