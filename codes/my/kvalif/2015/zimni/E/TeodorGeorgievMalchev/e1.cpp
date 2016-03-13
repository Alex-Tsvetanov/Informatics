#include <iostream>
using namespace std;

int main (){
    long long x,y,d,a1,a2;
    cin >> x >> y;
    cin >> d;
    a1=x*100+y;
    a2=((a1/2)-d)/2;
    cout << (a2+d)/100 << " " << (a2+d)%100 << endl;
    cout << (a2)/100 << " " << (a2)%100 << endl;
return 0;
}
