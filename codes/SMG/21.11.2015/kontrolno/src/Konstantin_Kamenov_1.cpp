#include<iostream>
#include<cstdio>
using namespace std ;
int main (  ) {
    int h1,m1,h2,m2;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
    int tm1=h1*60+m1;
    int tm2=h2*60+m2;
    int tot;
    if(tm1<=tm2){
        tot=tm2-tm1;
    }else{
    tot=(60*24-tm1)+tm2;
    }
    if(tot/60<10){
        cout<<"0";
    }
    cout<<tot/60<<":";
    if(tot%60<10){
        cout<<"0";
    }
    cout<<tot%60<<endl;
    return 0 ;
}
