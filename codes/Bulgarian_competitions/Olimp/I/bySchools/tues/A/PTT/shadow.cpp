#include<math.h>
#include<iostream>
using namespace std;
double sqr(double i){
    return i*i;
}
int main(){
    double a,b;
    cin>>a>>b;
    if(a==b){
        cout<<sqr(a)+(sqr(a/(2+sqrt(2)))*2);
    }else{
        cout<<(a*b+(sqr((a+b)/(2*(2+sqr(2))))*sin(45*a/b)));
    }
}
