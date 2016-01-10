#include <iostream>
#include <deque>
using namespace std;
int main(){
int n,ng=0,a,ng1,nm1=0;
cin>>n;
deque <int> redica;
for(int i=0;i<n;i++){
cin>>a;
redica.push_back(a);
}
int nm=redica[0];
for(int i=0;i<n;i++){
if(redica[i]<nm){
nm=redica[i];
nm1=i+1;
}
if(redica[i]>ng){
ng=redica[i];
ng1=i+1;
}
if(redica[i]==ng){
ng1=i+1;
}
}
if(nm1<ng1){
cout<<nm1<<" "<<ng1;
}else{
    cout<<ng1<<" "<<nm1;
}
}