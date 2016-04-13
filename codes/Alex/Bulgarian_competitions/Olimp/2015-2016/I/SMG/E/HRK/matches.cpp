#include<iostream>
using namespace std;
int main(){
long long a,b,c,d,obikolka,lice;
obikolka=0;
lice=0;
char first,second,thirt;
cin>>a>>b>>c>>d;

if(a==c && b==d){
    first='Y';
    second='E';
    thirt='S';
}else{
first='N';
second='O';
}
if(first=='Y' && second=='E' && thirt=='S'){
    lice=a*b;
}else{
    obikolka=a+b+c+d;
}
if(first=='Y' && second=='E' && thirt=='S'){
    cout<<first<<second<<thirt<<endl;
    cout<<lice;
}else{

     cout<<first<<second<<thirt<<endl;
    cout<<obikolka;

}

return 0;
}
