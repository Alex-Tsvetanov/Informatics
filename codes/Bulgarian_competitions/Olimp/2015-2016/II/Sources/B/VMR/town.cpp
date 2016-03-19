#include<iostream>
using namespace std;
int nar=0;
int main() {
int n,a,b;
int p,q;
cin>>n>>a>>b;
int box[n+1][n+1];
for(int i=0;i<n;i++){
    cin>>p;

    cin>>q;
    box[p][q]=1;
}
cout<<"X"<<endl;

return 0;
}
