#include <iostream>
using namespace std;
int main() {
  long long A,B,C,r=0,n,i;
    cin >>A>>B>>C;
    n=1;
    for(i=0;i<=n;i++) {
    n++;
    if(A==0) {
        cout <<r<<endl;
        break;
    }
        if(A==1&&B==0) {
        cout <<r<<endl;
        break;
    }
        if(A==1&&B==1&&C==0) {
        cout <<r<<endl;
        break;
    }
    A--;
    r++;
    B=B-1;
    r++;
    C=C-1;
    r++;
    B=B-1;
    r++;
    A=A-1;
    r++;
    B=B-1;
    r++;
    C=C-1;
    r++;
    }
    return 0;
}
