#include<iostream>
#include<algorithm>
using namespace std;
struct ch{
    short a[53],l=0;
    void dob(short k){
        if(l<52){
            a[l]=k;
            l++;
        }
    }
};
bool com (short a,short b){
    return a>b;
}
ch sbor(ch a,ch b){
    ch otg;
    int pr=0;
    for(int i=0;i<max(a.l,b.l);i++){
            otg.dob((a.a[i]+b.a[i]+pr)%10);
            pr= (a.a[i]+b.a[i]+pr)/10;
    }
    if(pr>0)    otg.dob(pr);
    return otg;
}
int main(){
    string vh;
    ch a,b;
    cin>>vh;
    for(int i=vh.size()-1;i>=0;i--){
        a.dob(vh[i]-'0');
        b.dob(vh[i]-'0');
    }
    sort(a.a+0,a.a+a.l,com);
    sort(b.a+0,b.a+b.l);
    if(a.a[0]==0 && a.l>1){
        for(int i=0;i<=a.l;i--){
            if(a.a[i]!=0){
                a.a[0]=a.a[i];
                a.a[i]=0;
            }
        }
    }
    ch ans=sbor(a,b);
    for(int i=ans.l-1;i>=0;i--){
        cout<<ans.a[i];
    }
    return 0;
}
