#include<iostream>
#include<queue>
using namespace std;
long long a,otg[2],y=0;
priority_queue<long long>Q;
long long n;
int main(){
cin>>n;
for(long long i=0;i<n;i++){
cin>>a;
Q.push(a);
}
while(Q.empty()==0){
a=Q.top();
Q.pop();
if(Q.top()==a){
Q.pop();
}else{
otg[y]=a;
y++;
}
if(y==2){
break;
}
}
cout<<min(otg[0],otg[1])<<" "<<max(otg[0],otg[1]);
return 0;
}
