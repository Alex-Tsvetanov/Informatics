#include <iostream>
#include <deque>
using namespace std;
int main(){
int m,p,k,a;
cin>>p>>m;
int gradove[p];
for(int i=0;i<p;i++){
gradove[i]=0;

}
for(int i=0;i<m;i++){
cin>>k;
gradove[k]++;
cin>>k;
gradove[k]++;
}
cin>>k;
int count=0;
deque <int> gradovee;
for(int i=0;i<p;i++){
if(gradove[i]>=k){
    count++;
gradovee.push_back(i);
}
}
if(count==0){
cout<<"0";
}else{
    cout<<count<<endl;
for(int i=0;i<count;i++){
cout<<gradovee[i]<<" ";

}
}

}