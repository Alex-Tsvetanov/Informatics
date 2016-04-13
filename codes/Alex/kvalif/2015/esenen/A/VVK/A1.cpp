#include<iostream>
#include<cmath>
using namespace std;
double find_cos(int,int);
double find_sin(int,int);
int main(){
int n;
cin>>n;
int a[100][2];
int cos[100][1],sin[100][1];
for(int i=0;i<n+1;i++){
    cin>>a[i][0]>>a[i][1];
}
for(int i=1;i<n+1;i++){
    a[i][0] = a[i][0] - a[0][0];
    a[i][1] = a[i][1] - a[0][1];
}
a[0][0] = 0;
a[0][1] = 0;
int p = n-1;
for(int i=1;i<n+1;i++){
    cos[i][0] = find_cos(a[i][0],a[i][1]);
    cos[i][1] = i;
    sin[i][0] = find_sin(a[i][0],a[i][1]);
    sin[i][1] = i;
}
cout<<endl;
for(int i=1;i<n;i++){
        if(cos[i][0] > sin[i][0])
    cout<<i<<" "<<i+1<<endl;
}
return 0;
}
double find_cos(int x,int y){
    double c=sqrt(x*x + y*y);
    return x/c;
}
double find_sin(int x,int y){
    double c=sqrt(x*x + y*y);
    return y/c;
}
