#include <iostream>
using namespace std;
int main(){
long long x,y,d,q,w,e,w2,e2;
cin >> x;
cin >> y;
cin >> d;
q=(x*100+y)/2;
e=(q-d)/2;
w=e+d;
w2=w;
e2=e;
w=w/100;
e=e/100;
w2=w2-w*100;
e2=e2-e*100;
    cout << w<<" "<<w2<<endl <<e<<" "<<e2;
return 0;
}
