#include<iostream>
using namespace std;
long long r[21],n,i;
int main(){
cin>>r[0]>>r[1]>>r[2]>>n;
if(i<3){
cout<<r[n-1];
}else{
for(i=3;i<n;i++){
r[i]=r[i-3]+r[i-2]+r[i-1];
}
cout<<r[n-1];
}
cout<<endl;
return 0;
}
