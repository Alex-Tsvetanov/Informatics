#include<iostream>
using namespace std;
int main () {
long long X;
int o, i, broi, a, b, rezervno;
cin >> X;
b = 0;

for(a = 2;X > 1;a++){
    rezervno = X;
        while(X % a == 0){
        X = X / a;
        ++b;
    }
    if(b != 0){
        cout << "1" << endl << a << " " << b << endl;
    }
}




return 0;
}
