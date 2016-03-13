#include <iostream>
using namespace std;

int main (){
    long long a,b,c,d,e,f,g,h,i,a1,a2,a3,a4[3];
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    cin >> g >> h >> i;
    cin >> a2 >> a3;
    a1=a2*a3;
    c=c+b*100;
    f=f+e*100;
    i=i+h*100;
    if(a1*4%a==0){
        a4[0]=(a1*4/a)*c;
    }else{
       a4[0]=(a1*4/a+1)*c;
    }
    if(a1*4%d==0){
        a4[1]=(a1*4/d)*f;
    }else{
       a4[1]=(a1*4/d+1)*f;
    }
    if(a1*4%g==0){
        a4[2]=(a1*4/g)*i;
    }else{
       a4[2]=(a1*4/g+1)*i;
    }
    if(a4[0]>=a4[2] and a4[2]<=a4[1]){
            a2=a4[2]/100;
            a3=a4[2]%100;
        cout << a2 << " " << a3 << endl;
    }
    if(a4[0]>=a4[1] and a4[1]<=a4[2]){
            a2=a4[1]/100;
            a3=a4[1]%100;
        cout << a2 << " " << a3 << endl;
    }
    if(a4[1]>=a4[0] and a4[0]<=a4[2]){
            a2=a4[0]/100;
            a3=a4[0]%100;
        cout << a2 << " " << a3 << endl;
    }
return 0;
}
