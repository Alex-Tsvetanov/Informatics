#include<cstdio>
#include<iostream>
using namespace std;
int which_qua(int,int);
int main(){
int a,b;
scanf("%d",&a);
scanf("%d",&b);
int a11,a12,a21,a22,b11,b12,b21,b22,c11,c12,c21,c22;
cin>>a11>>a12>>a21>>a22>>b11>>b12>>b21>>b22>>c11>>c12>>c21>>c22;
int max_procent = 0;
if(which_qua(a11,a12) == 1 and which_qua(a21,a22) == 1) max_procent = 100;
if(which_qua(b11,b12) == 1 and which_qua(b21,b22) == 1) max_procent = 100;
if(which_qua(c11,c12) == 1 and which_qua(c21,c22) == 1) max_procent = 100;
cout<<max_procent<<endl;
return 0;
}
int which_qua(int a,int b){
    if(a >= 0 and b >= 0) return 1;
    else if(a <= 0 and b >= 0) return 2;
    else if(a <= 0 and b <= 0) return 3;
    else return 4;

}
