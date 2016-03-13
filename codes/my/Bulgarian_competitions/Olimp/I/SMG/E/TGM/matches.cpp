#include <iostream>
using namespace std;

int main (){
    long long a,b,c,d,buf=0;
    cin >> a >> b >> c >> d;
       if(buf==0){
    if(a==b and c==d and a==c and b==d and a==d and b==c){
        cout << "YES" << endl;
        cout << a*c << endl;
        buf++;
    }
       }
    if(buf==0){
    if(a==b and c==d and a!=c and b!=d and a!=d and b!=c){
        cout << "YES" << endl;
        cout << a*c << endl;
        buf++;
    }
    }
    if(buf==0){
    if(a!=b and c!=d and a==c and b==d and a!=d and b!=c){
        cout << "YES" << endl;
        cout << a*b << endl;
        buf++;
    }
    }
    if(buf==0){
    if(a!=b and c!=d and a!=c and b!=d and a==d and b==c){
        cout << "YES" << endl;
        cout << a*c << endl;
        buf++;
    }
    }
        if(buf==0){
    if(a!=b and c!=d and a==c and b==d and a==d and b==c){
        cout << "YES" << endl;
        cout << a*b << endl;
        buf++;
    }
    }
        if(buf==0){
    if(a==b and c==d and a!=c and b!=d and a==d and b==c){
        cout << "YES" << endl;
        cout << a*c << endl;
        buf++;
    }
    }
        if(buf==0){
    if(a==b and c==d and a==c and b==d and a!=d and b!=c){
        cout << "YES" << endl;
        cout << a*d << endl;
        buf++;
    }else{
        cout << "NO" << endl;
        cout << a+b+c+d << endl;
        buf++;
    }
    }
    return 0;
}
