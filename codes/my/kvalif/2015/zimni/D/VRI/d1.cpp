#include<iostream>
using namespace std;
int main(){
long long redica[1000], nomer;
for(long long i=0 ; i<3 ; i++) {
    cin>>redica[i];
}
    cin>>nomer;
for(long long i=3 ; i<21 ; i++) {
    redica[i]=redica[i-1]+redica[i-2]+redica[i-3];
}
    cout<<redica[nomer-1];
cout<<endl;
return 0;
}
