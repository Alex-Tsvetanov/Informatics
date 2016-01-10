#include<iostream>
using namespace std;
int main(){
int n,m,k=0;
bool zvezda=false;
int sum=0;
cin>>n>>m;
char a[n][m];
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
}
for(int q=0;q<n;q++){
    for(int p=0;p<m;p++){
        if(a[k][p]=='*'){
        zvezda=true;
        }else{
        zvezda=false;
        }
    }
    if(zvezda==true){
    k++;
    }
    if(zvezda==false or k==n){
    sum+=k*(k+1)/2;
    k=0;
    }
}
cout<<sum<<"\n";


return 0;
}