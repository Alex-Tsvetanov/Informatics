#include <iostream>
using namespace std;

int main (){
    long long a,b,c,bonbons=0;
    cin >> a >> b >> c;
    while(a!=0,b!=0,c!=0){
        a--;
        if(b==0){
            bonbons=bonbons+1;
            break;
        }
        b--;
        if(c==0){
            bonbons=bonbons+2;
            break;
        }
        c--;
        if(b==0){
            bonbons=bonbons+3;
            break;
        }
        b--;
        bonbons=bonbons+4;
    }
    cout << bonbons << endl;
return 0;
}
