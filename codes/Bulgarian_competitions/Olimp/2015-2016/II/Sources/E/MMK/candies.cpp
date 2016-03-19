#include<iostream>
using namespace std;

long long i, k=1, br, a, b, c;

int main () {
    cin>>a>>b>>c;
    while (1) {
        if (k==1) {
            br++;
            if (b==0) {
                cout<<br<<endl;
                return 0;
            }
            b--;
            br++;
            if (c==0) {
                cout<<br<<endl;
                return 0;
            }
            c--;
            k=3;
        }
        if (k==3) {
            br++;
            if (b==0) {
                cout<<br<<endl;
                return 0;
            }
            b--;
            br++;
            if (a==0) {
                cout<<br<<endl;
                return 0;
            }
            a--;
            k=1;
        }
    }
    return 0;
}
