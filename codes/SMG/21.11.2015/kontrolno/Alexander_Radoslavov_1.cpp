#include<iostream>
using namespace std;
struct chas{
    int ch;
};
int main(){
    chas a,b;
    int c;
    string vh;
    cin>>vh;
    a.ch=(vh[0]-'0')*60+(vh[1]-'0')*6+(vh[3]-'0')*10+(vh[4]-'0');
    cin>>vh;
    b.ch=(vh[0]-'0')*60+(vh[1]-'0')*6+(vh[3]-'0')*10+(vh[4]-'0');
    if(b.ch>a.ch){
        c=b.ch-a.ch;
    }else{
        c=b.ch-a.ch+1440;
    }
    if(c/60<10) cout<<0;
    cout<<c/60;
    cout<<":";
    if(c%60<10) cout<<0;
    cout<<c%60;
    return 0;
}
