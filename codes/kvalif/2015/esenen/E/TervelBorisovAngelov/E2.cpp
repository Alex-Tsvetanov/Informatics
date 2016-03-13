#include <iostream>
using namespace std;
int main (){
    long long m,c,k;
    cin>>m>>c>>k;
    if(c*k>=100){
        c-100 && m+1;
    }
    cout<<m*k<<"  "<<c*k;
return 0;
}
