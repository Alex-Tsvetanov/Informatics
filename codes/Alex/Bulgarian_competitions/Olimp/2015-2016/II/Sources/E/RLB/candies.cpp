#include<iostream>
using namespace std;
#define ll long long int
int main(){
    ll a, b, c;
    cin >> a >> b >> c;

    ll p = 1;
    ll d = 0;
    while(a != 0 and b != 0 and c != 0){
        if(p == 1){
            a--;
            d++;
            if(a == 0){
                cout << d << endl;
                break;
            }
            b--;
            d++;
            if(b == 0){
                cout << d << endl;
                break;
            }
            c--;
            d++;
            if(c == 0){
                cout << d << endl;
                break;
            }
        }
        if(p == 2){
            b = b - 2;
            d = d + 2;
            if(b == 0){
                cout << d << endl;
                break;
            }
            a--;
            d++;
            if(a == 0){
                cout << d << endl;
                break;
            }
        }
        if(p == 2)
            p = 1;
    }

    return 0;
}
