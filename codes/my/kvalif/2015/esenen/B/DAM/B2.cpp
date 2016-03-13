#include <iostream>
using namespace std;
int main () {
int N,M;
cin>>N>>M;
int m[200];
int n[200];
for (int i=0;i<M;i++){
    cin>>m[i];
}
for (int i=0;i<=N;i++){
    cin>>n[i];
}
cout<<n[0]+n[2]<<" "<<M+3<<endl;


return 0;
}
