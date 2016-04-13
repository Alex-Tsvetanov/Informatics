#include<iostream>
using namespace std;
int main ()
{
long long bonboni[3], broy=0, kupa=0, deltaX=1;
cin>>bonboni[0]>>bonboni[1]>>bonboni[2];
while(bonboni[kupa]>0){
    bonboni[kupa]--;
    broy++;
    if(kupa==0 && deltaX==-1){
        deltaX=1;
    }else if(kupa==2 && deltaX==1){
        deltaX=-1;
    }
    kupa=kupa+deltaX;
}
cout<<broy<<endl;
return 0;
}
