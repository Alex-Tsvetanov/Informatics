#include <iostream>
using namespace std;
long long h[1000000],x[100000],xl=0;
int main(){
long long s,i,o,n;
cin>>n;
for(i=0; i<n; i++){
    cin>>h[i];
}
for(i=0; i<n; i++){
    s=0;
    for(o=i; o<n; o++){
    if(h[i]<h[o]){s=1;}
    }
    if(s==0){
        x[xl]=h[i];
        xl++;
    }
}

for(i=0; i<xl; i++){
cout<<x[i]<<" ";
}

return 0;
}
