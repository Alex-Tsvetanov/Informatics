#include<iostream>
using namespace std;
int main() {
long  long a=0, b=0, c=0, d=0, obikolka=0, lice=-1, stranaA=0, stranaB=0;
bool mojeLiDaSaNapraviPravougulnik = false;
cin>>a>>b>>c>>d;
if(a==b && b==c && c==d){
    mojeLiDaSaNapraviPravougulnik=true;
    lice = a*a;
}
if(a==b){
    stranaA=a;
    if(c==d){
        stranaB=c;
        mojeLiDaSaNapraviPravougulnik=true;
    }
}
if(a==c){
    stranaA=a;
    if(b==d){
        stranaB=b;
        mojeLiDaSaNapraviPravougulnik=true;
    }
}
if(a==d){
    stranaA=a;
    if(b==c){
        stranaB=b;
        mojeLiDaSaNapraviPravougulnik=true;
    }
}
if(!mojeLiDaSaNapraviPravougulnik){
    cout<<"NO"<<endl;
    obikolka = a+b+c+d;
    cout<<obikolka;
}
if(mojeLiDaSaNapraviPravougulnik){
    if(lice==-1){
        lice = stranaA*stranaB;
    }
    cout<<"YES"<<endl<<lice;
}
return 0;
}
