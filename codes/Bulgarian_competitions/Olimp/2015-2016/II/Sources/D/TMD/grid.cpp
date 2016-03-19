#include<iostream>
using namespace std;
long long m,n,i,i2,k,p[200][200],i3,i4;
bool chb[200][200];
int main(){
cin>>m>>n;
for(i=0;i<200;i++){
for(i2=0;i2<200;i2++){
chb[i][i2]=1;
}
}
for(i=1;i<m+1;i++){
for(i2=1;i2<n+1;i2++){
cin>>chb[i][i2];
if(chb[i][i2]==1){
p[i][i2]=-1;
}
}
}
for(i=1;i<m+1;i++){
for(i2=1;i2<n+1;i2++){
if(chb[i][i2]==0){
k++;
p[i][i2]=k;
for(i3=1;i3<m+1;i3++){
for(i4=1;i4<n+1;i4++){
if(chb[i3][i4]==0 and p[i3][i4]==0 and p[i3+1][i4]==k){
p[i3][i4]=k;
chb[i3][i4]=1;
}
if(chb[i3][i4]==0 and p[i3][i4]==0 and p[i3-1][i4]==k){
p[i3][i4]=k;
chb[i3][i4]=1;
}
if(chb[i3][i4]==0 and p[i3][i4]==0 and p[i3][i4+1]==k){
p[i3][i4]=k;
chb[i3][i4]=1;
}
if(chb[i3][i4]==0 and p[i3][i4]==0 and p[i3][i4-1]==k){
p[i3][i4]=k;
chb[i3][i4]=1;
}
}
}
}
}
}
cout<<k<<endl;
return 0;
}
