#include<iostream>
using namespace std;
int main(){
    long long s,s1,s2,so,lv,lv1,lv2,st,st1,st2,a,b,c1,c,c2;
    cin>>s>>lv>>st;
    cin>>s1>>lv1>>st1;
    cin>>s2>>lv2>>st2;
    cin>>a>>b;
    so=a*b*4;

    if(so%s==0){
        c=so/s;
        c=c*(lv*100+st);
    }else{
        c=so/s+1;
        c=c*(lv*100+st);
    }

    if(so%s1==0){
        c1=so/s1;
        c1=c1*(lv1*100+st1);
    }else{
        c1=so/s1+1;
        c1=c1*(lv1*100+st1);
    }

    if(so%s2==0){
        c2=so/s2;
        c2=c2*(lv2*100+st2);
    }else{
        c2=so/s2+1;
        c2=c2*(lv2*100+st2);
    }
    if(c<c1 and c<c2){
        c=c;
        lv=c/100;
        st=c%100;
        cout<<lv<<" "<<st;
        return 0;
    }

    if(c1<c and c1<c2){
        c1=c1;
        lv=c1/100;
        st=c1%100;
        cout<<lv<<" "<<st;
        return 0;
    }

    if(c2<c1 and c2<c){
        c2=c2;
        lv=c2/100;
        st=c2%100;
        cout<<lv<<" "<<st;
        return 0;
    }
return 0;
}
